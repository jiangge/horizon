#pragma once
#include "core/tool.hpp"
#include <forward_list>

namespace horizon {
class ToolSetViaNet : public ToolBase {
public:
    ToolSetViaNet(IDocument *c, ToolID tid);
    ToolResponse begin(const ToolArgs &args) override;
    ToolResponse update(const ToolArgs &args) override;
    bool can_begin() override;
    bool is_specific() override
    {
        return true;
    }

private:
    std::set<class Via *> get_vias();
};
} // namespace horizon
