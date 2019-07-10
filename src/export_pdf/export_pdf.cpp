#include "export_pdf.hpp"
#include "canvas_pdf.hpp"
#include <podofo/podofo.h>
#include "util/util.hpp"
#include "schematic/schematic.hpp"

namespace horizon {

static void cb_nop(std::string, double)
{
}

void export_pdf(const class Schematic &sch, const class PDFExportSettings &settings,
                std::function<void(std::string, double)> cb)
{
    if (!cb)
        cb = &cb_nop;
    cb("Initializing", 0);

    PoDoFo::PdfStreamedDocument document(settings.output_filename.c_str());
    PoDoFo::PdfPainterMM painter;
    auto info = document.GetInfo();
    info->SetCreator("horizon EDA");
    info->SetProducer("horizon EDA");
    if (sch.title_block_values.count("author")) {
        info->SetAuthor(sch.title_block_values.at("author"));
    }
    std::string title = "Schematic";
    if (sch.title_block_values.count("project_title")) {
        title = sch.title_block_values.at("project_title");
    }
    info->SetTitle(title);

    std::vector<const Sheet *> sheets;
    for (const auto &it : sch.sheets) {
        sheets.push_back(&it.second);
    }
    std::sort(sheets.begin(), sheets.end(), [](auto a, auto b) { return a->index < b->index; });


    auto font = document.CreateFont("Helvetica");

    auto outlines = document.GetOutlines();
    auto proot = outlines->CreateRoot(title);

    bool first_outline_item = true;

    CanvasPDF ca(&painter, font, settings);
    ca.use_layer_colors = false;
    for (const auto sheet : sheets) {
        cb("Exporting sheet " + format_m_of_n(sheet->index, sheets.size()), ((double)sheet->index) / sheets.size());

        auto page = document.CreatePage(PoDoFo::PdfRect(0, 0, to_pt(sheet->frame.width), to_pt(sheet->frame.height)));
        painter.SetPage(page);
        painter.SetLineCapStyle(PoDoFo::ePdfLineCapStyle_Round);
        painter.SetFont(font);
        painter.SetColor(0, 0, 0);
        painter.SetTextRenderingMode(PoDoFo::ePdfTextRenderingMode_Invisible);

        ca.update(*sheet);

        painter.FinishPage();


        if (first_outline_item)
            proot->CreateChild(sheet->name, PoDoFo::PdfDestination(page));
        else
            proot->Last()->CreateNext(sheet->name, PoDoFo::PdfDestination(page));
        first_outline_item = false;
    }
    document.Close();
}
} // namespace horizon
