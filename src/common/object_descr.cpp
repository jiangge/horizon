#include "object_descr.hpp"
#include "hole.hpp"
#include "dimension.hpp"
#include "schematic/schematic_symbol.hpp"
#include "shape.hpp"
#include "pool/symbol.hpp"

namespace horizon {

const std::string &ObjectDescription::get_name_for_n(size_t n) const
{
    if (n == 1)
        return name;
    else
        return name_pl;
}

const std::map<ObjectType, ObjectDescription> object_descriptions = {
        {ObjectType::SYMBOL_PIN,
         {"Symbol Pin",
          "Symbol Pins",
          {
                  {ObjectProperty::ID::NAME, {ObjectProperty::Type::STRING_RO, "Name", 0}},
                  {ObjectProperty::ID::NAME_VISIBLE, {ObjectProperty::Type::BOOL, "Name visible", 1}},
                  {ObjectProperty::ID::PAD_VISIBLE, {ObjectProperty::Type::BOOL, "Pad visible", 2}},
                  {ObjectProperty::ID::LENGTH, {ObjectProperty::Type::LENGTH, "Length", 3}},
                  {ObjectProperty::ID::PIN_NAME_ORIENTATION,
                   {ObjectProperty::Type::ENUM,
                    "Name Orientation",
                    4,
                    {
                            {static_cast<int>(SymbolPin::NameOrientation::IN_LINE), "In Line"},
                            {static_cast<int>(SymbolPin::NameOrientation::PERPENDICULAR), "Perpendicular"},
                            {static_cast<int>(SymbolPin::NameOrientation::HORIZONTAL), "Horizontal"},
                    }}},
                  {ObjectProperty::ID::DOT, {ObjectProperty::Type::BOOL, "Inverted", 5}},
                  {ObjectProperty::ID::CLOCK, {ObjectProperty::Type::BOOL, "Clock", 6}},
                  {ObjectProperty::ID::SCHMITT, {ObjectProperty::Type::BOOL, "Schmitt", 7}},
                  {ObjectProperty::ID::DRIVER,
                   {ObjectProperty::Type::ENUM,
                    "Driver",
                    8,
                    {
                            {static_cast<int>(SymbolPin::Decoration::Driver::DEFAULT), "Default"},
                            {static_cast<int>(SymbolPin::Decoration::Driver::OPEN_COLLECTOR), "Open Collector"},
                            {static_cast<int>(SymbolPin::Decoration::Driver::OPEN_COLLECTOR_PULLUP), "O.C. w/  pullup"},
                            {static_cast<int>(SymbolPin::Decoration::Driver::OPEN_EMITTER), "Open Emitter"},
                            {static_cast<int>(SymbolPin::Decoration::Driver::OPEN_EMITTER_PULLDOWN),
                             "O.E. w/  pulldown"},
                            {static_cast<int>(SymbolPin::Decoration::Driver::TRISTATE), "Tristate"},
                    }}},
          }}},
        {ObjectType::JUNCTION, {"Junction", "Junctions", {}}},
        {ObjectType::MODEL_3D, {"3D Model", "3D Models", {}}},
        {ObjectType::INVALID, {"Invalid", "Invalid", {}}},
        {ObjectType::SYMBOL, {"Symbol", "Symbols", {}}},
        {ObjectType::NET_CLASS, {"Net class", "Net classes", {}}},
        {ObjectType::UNIT, {"Unit", "Units", {}}},
        {ObjectType::ENTITY, {"Entity", "Entities", {}}},
        {ObjectType::PACKAGE, {"Package", "Packages", {}}},
        {ObjectType::PADSTACK, {"Padstack", "Padstacks", {}}},
        {ObjectType::PART, {"Part", "Parts", {}}},
        {ObjectType::LINE_NET, {"Net line", "Net lines", {}}},
        {ObjectType::BUS_LABEL, {"Bus label", "Bus labels", {}}},
        {ObjectType::BUS_RIPPER, {"Bus ripper", "Bus rippers", {}}},
        {ObjectType::SCHEMATIC_SYMBOL,
         {"Symbol",
          "Symbols",
          {
                  {ObjectProperty::ID::DISPLAY_DIRECTIONS, {ObjectProperty::Type::BOOL, "Pin directions", 0}},
                  {ObjectProperty::ID::PIN_NAME_DISPLAY,
                   {ObjectProperty::Type::ENUM,
                    "Pin display",
                    1,
                    {
                            {static_cast<int>(SchematicSymbol::PinDisplayMode::SELECTED_ONLY), "Sel. only"},
                            {static_cast<int>(SchematicSymbol::PinDisplayMode::BOTH), "Both"},
                            {static_cast<int>(SchematicSymbol::PinDisplayMode::ALL), "All"},
                            {static_cast<int>(SchematicSymbol::PinDisplayMode::CUSTOM_ONLY), "Custom only"},
                    }}},
                  {ObjectProperty::ID::DISPLAY_ALL_PADS, {ObjectProperty::Type::BOOL, "Show all pads", 2}},
          }}},
        {ObjectType::POWER_SYMBOL, {"Power symbol", "Power symbols", {}}},
        {ObjectType::POLYGON_EDGE, {"Polygon edge", "Polygon edges", {}}},
        {ObjectType::POLYGON_VERTEX, {"Polygon vertex", "Polygon vertices", {}}},
        {ObjectType::POLYGON_ARC_CENTER, {"Polygon arc center", "Polygon arc centers", {}}},
        {ObjectType::VIA,
         {"Via",
          "Vias",
          {
                  {ObjectProperty::ID::FROM_RULES, {ObjectProperty::Type::BOOL, "From rules", 1}},
                  {ObjectProperty::ID::NAME, {ObjectProperty::Type::STRING_RO, "Net", 0}},
                  {ObjectProperty::ID::LOCKED, {ObjectProperty::Type::BOOL, "Locked", 2}},
          }}},
        {ObjectType::SHAPE,
         {"Shape",
          "Shapes",
          {
                  {ObjectProperty::ID::LAYER, {ObjectProperty::Type::LAYER, "Layer", 0}},
                  {ObjectProperty::ID::PARAMETER_CLASS, {ObjectProperty::Type::STRING, "Parameter class", 1}},
                  {ObjectProperty::ID::POSITION_X, {ObjectProperty::Type::DIM, "Position X", 2}},
                  {ObjectProperty::ID::POSITION_Y, {ObjectProperty::Type::DIM, "Position Y", 3}},
                  {ObjectProperty::ID::ANGLE, {ObjectProperty::Type::ANGLE, "Angle", 4}},
                  {ObjectProperty::ID::FORM,
                   {ObjectProperty::Type::ENUM,
                    "Form",
                    5,
                    {
                            {static_cast<int>(Shape::Form::RECTANGLE), "Rectangle"},
                            {static_cast<int>(Shape::Form::OBROUND), "Obround"},
                            {static_cast<int>(Shape::Form::CIRCLE), "Circle"},
                    }}},
                  {ObjectProperty::ID::WIDTH, {ObjectProperty::Type::DIM, "Width", 6}},
                  {ObjectProperty::ID::HEIGHT, {ObjectProperty::Type::DIM, "Height", 7}},
                  {ObjectProperty::ID::DIAMETER, {ObjectProperty::Type::DIM, "Diamter", 8}},
          }}},
        {ObjectType::LINE,
         {"Line",
          "Lines",
          {
                  {ObjectProperty::ID::WIDTH, {ObjectProperty::Type::LENGTH, "Width", 0}},
                  {ObjectProperty::ID::LAYER, {ObjectProperty::Type::LAYER, "Layer", 1}},
          }}},
        {ObjectType::ARC,
         {"Arc",
          "Arcs",
          {
                  {ObjectProperty::ID::WIDTH, {ObjectProperty::Type::LENGTH, "Width", 0}},
                  {ObjectProperty::ID::LAYER, {ObjectProperty::Type::LAYER, "Layer", 1}},
          }}},
        {ObjectType::TEXT,
         {"Text",
          "Texts",
          {
                  {ObjectProperty::ID::SIZE, {ObjectProperty::Type::LENGTH, "Size", 1}},
                  {ObjectProperty::ID::WIDTH, {ObjectProperty::Type::LENGTH, "Width", 2}},
                  {ObjectProperty::ID::TEXT, {ObjectProperty::Type::STRING_MULTILINE, "Text", 0}},
                  {ObjectProperty::ID::LAYER, {ObjectProperty::Type::LAYER, "Layer", 3}},
                  {ObjectProperty::ID::POSITION_X, {ObjectProperty::Type::DIM, "Position X", 4}},
                  {ObjectProperty::ID::POSITION_Y, {ObjectProperty::Type::DIM, "Position Y", 5}},
                  {ObjectProperty::ID::ANGLE, {ObjectProperty::Type::ANGLE, "Angle", 6}},
                  {ObjectProperty::ID::MIRROR, {ObjectProperty::Type::BOOL, "Mirror", 7}},
                  {ObjectProperty::ID::FONT,
                   {ObjectProperty::Type::ENUM,
                    "Font",
                    8,
                    {
                            {static_cast<int>(TextData::Font::SIMPLEX), "Simplex"},
                            {static_cast<int>(TextData::Font::DUPLEX), "Duplex"},
                            {static_cast<int>(TextData::Font::TRIPLEX), "Triplex"},
                            {static_cast<int>(TextData::Font::TRIPLEX_ITALIC), "Triplex Italic"},
                            {static_cast<int>(TextData::Font::COMPLEX), "Complex"},
                            {static_cast<int>(TextData::Font::COMPLEX_ITALIC), "Complex Italic"},
                            {static_cast<int>(TextData::Font::SCRIPT_SIMPLEX), "Script Simplex"},
                            {static_cast<int>(TextData::Font::SCRIPT_COMPLEX), "Script Complex"},
                    }}},

          }}},
        {ObjectType::COMPONENT,
         {"Component",
          "Components",
          {
                  {ObjectProperty::ID::REFDES, {ObjectProperty::Type::STRING, "Ref. Desig.", 0}},
                  {ObjectProperty::ID::VALUE, {ObjectProperty::Type::STRING, "Value", 2}},
                  {ObjectProperty::ID::MPN, {ObjectProperty::Type::STRING_RO, "MPN", 1}},
          }}},
        {ObjectType::NET,
         {"Net",
          "Nets",
          {
                  {ObjectProperty::ID::NAME, {ObjectProperty::Type::STRING, "Name", 0}},
                  {ObjectProperty::ID::IS_POWER, {ObjectProperty::Type::BOOL, "Is power net", 2}},
                  {ObjectProperty::ID::NET_CLASS, {ObjectProperty::Type::NET_CLASS, "Net class", 1}},
                  {ObjectProperty::ID::DIFFPAIR, {ObjectProperty::Type::STRING_RO, "Diff. pair", 3}},
          }}},
        {ObjectType::NET_LABEL,
         {"Net label",
          "Net labels",
          {
                  {ObjectProperty::ID::SIZE, {ObjectProperty::Type::LENGTH, "Size", 2}},
                  {ObjectProperty::ID::OFFSHEET_REFS, {ObjectProperty::Type::BOOL, "Offsheet refs", 1}},
                  {ObjectProperty::ID::NAME, {ObjectProperty::Type::STRING_RO, "Net name", 0}},
          }}},
        {ObjectType::POLYGON,
         {"Polygon",
          "Polygons",
          {
                  {ObjectProperty::ID::LAYER, {ObjectProperty::Type::LAYER, "Layer", 0}},
                  {ObjectProperty::ID::PARAMETER_CLASS, {ObjectProperty::Type::STRING, "Parameter class", 1}},
                  {ObjectProperty::ID::USAGE, {ObjectProperty::Type::STRING_RO, "Usage", 2}},
          }}},
        {ObjectType::HOLE,
         {"Hole",
          "Holes",
          {
                  {ObjectProperty::ID::DIAMETER, {ObjectProperty::Type::LENGTH, "Diameter", 1}},
                  {ObjectProperty::ID::LENGTH, {ObjectProperty::Type::LENGTH, "Length", 2}},
                  {ObjectProperty::ID::PLATED, {ObjectProperty::Type::BOOL, "Plated", 3}},
                  {ObjectProperty::ID::SHAPE,
                   {ObjectProperty::Type::ENUM,
                    "Shape",
                    0,
                    {
                            {static_cast<int>(Hole::Shape::ROUND), "Round"},
                            {static_cast<int>(Hole::Shape::SLOT), "Slot"},
                    }}},
                  {ObjectProperty::ID::PARAMETER_CLASS, {ObjectProperty::Type::STRING, "Parameter class", 4}},
                  {ObjectProperty::ID::POSITION_X, {ObjectProperty::Type::DIM, "Position X", 5}},
                  {ObjectProperty::ID::POSITION_Y, {ObjectProperty::Type::DIM, "Position Y", 6}},
                  {ObjectProperty::ID::ANGLE, {ObjectProperty::Type::ANGLE, "Angle", 7}},
          }}},
        {ObjectType::PAD,
         {"Pad",
          "Pads",
          {
                  {ObjectProperty::ID::NAME, {ObjectProperty::Type::STRING, "Name", 0}},
                  {ObjectProperty::ID::VALUE, {ObjectProperty::Type::STRING_RO, "Padstack", 1}},
                  {ObjectProperty::ID::PAD_TYPE, {ObjectProperty::Type::STRING_RO, "Pad type", 2}},
                  {ObjectProperty::ID::ANGLE, {ObjectProperty::Type::ANGLE, "Angle", 5}},
                  {ObjectProperty::ID::POSITION_X, {ObjectProperty::Type::DIM, "Position X", 3}},
                  {ObjectProperty::ID::POSITION_Y, {ObjectProperty::Type::DIM, "Position Y", 4}},
          }}},
        {ObjectType::BOARD_HOLE,
         {"Hole",
          "Holes",
          {
                  {ObjectProperty::ID::NAME, {ObjectProperty::Type::STRING_RO, "Padstack", 0}},
                  {ObjectProperty::ID::VALUE, {ObjectProperty::Type::STRING_RO, "Net", 1}},
                  {ObjectProperty::ID::PAD_TYPE, {ObjectProperty::Type::STRING_RO, "Type", 2}},
                  {ObjectProperty::ID::ANGLE, {ObjectProperty::Type::ANGLE, "Angle", 5}},
                  {ObjectProperty::ID::POSITION_X, {ObjectProperty::Type::DIM, "Position X", 3}},
                  {ObjectProperty::ID::POSITION_Y, {ObjectProperty::Type::DIM, "Position Y", 4}},
          }}},
        {ObjectType::BOARD_PACKAGE,
         {"Package",
          "Packages",
          {
                  {ObjectProperty::ID::FLIPPED, {ObjectProperty::Type::BOOL, "Flipped", 4}},
                  {ObjectProperty::ID::REFDES, {ObjectProperty::Type::STRING_RO, "Ref. Desig.", 0}},
                  {ObjectProperty::ID::ALTERNATE_PACKAGE, {ObjectProperty::Type::NET_CLASS, "Package", 1}},
                  {ObjectProperty::ID::VALUE, {ObjectProperty::Type::STRING_RO, "Value", 3}},
                  {ObjectProperty::ID::MPN, {ObjectProperty::Type::STRING_RO, "MPN", 2}},
                  {ObjectProperty::ID::ANGLE, {ObjectProperty::Type::ANGLE, "Angle", 7}},
                  {ObjectProperty::ID::POSITION_X, {ObjectProperty::Type::DIM, "Position X", 5}},
                  {ObjectProperty::ID::POSITION_Y, {ObjectProperty::Type::DIM, "Position Y", 6}},
          }}},
        {ObjectType::TRACK,
         {"Track",
          "Tracks",
          {
                  {ObjectProperty::ID::WIDTH, {ObjectProperty::Type::LENGTH, "Width", 3}},
                  {ObjectProperty::ID::LAYER, {ObjectProperty::Type::LAYER_COPPER, "Layer", 1}},
                  {ObjectProperty::ID::NAME, {ObjectProperty::Type::STRING_RO, "Net", 0}},
                  {ObjectProperty::ID::NET_CLASS, {ObjectProperty::Type::STRING_RO, "Net class", 4}},
                  {ObjectProperty::ID::WIDTH_FROM_RULES, {ObjectProperty::Type::BOOL, "Width from rules", 2}},
                  {ObjectProperty::ID::LOCKED, {ObjectProperty::Type::BOOL, "Locked", 5}},
          }}},
        {ObjectType::PLANE,
         {"Plane",
          "Planes",
          {
                  {ObjectProperty::ID::WIDTH, {ObjectProperty::Type::LENGTH, "Min. Width", 2}},
                  {ObjectProperty::ID::NAME, {ObjectProperty::Type::STRING_RO, "Net", 0}},
                  {ObjectProperty::ID::FROM_RULES, {ObjectProperty::Type::BOOL, "From rules", 1}},
          }}},
        {ObjectType::DIMENSION,
         {"Dimension",
          "Dimensions",
          {
                  {ObjectProperty::ID::SIZE, {ObjectProperty::Type::LENGTH, "Size", 0}},
                  {ObjectProperty::ID::MODE,
                   {ObjectProperty::Type::ENUM,
                    "Mode",
                    1,
                    {
                            {static_cast<int>(Dimension::Mode::DISTANCE), "Distance"},
                            {static_cast<int>(Dimension::Mode::HORIZONTAL), "Horizontal"},
                            {static_cast<int>(Dimension::Mode::VERTICAL), "Vertical"},
                    }}},
          }}},
        {ObjectType::FRAME, {"Frame", "Frames", {}}},
        {ObjectType::KEEPOUT,
         {"Keepout",
          "Keepouts",
          {
                  {ObjectProperty::ID::KEEPOUT_CLASS, {ObjectProperty::Type::STRING, "Keepout class", 0}},
          }}},
};
} // namespace horizon
