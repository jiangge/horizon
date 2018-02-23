#pragma once
#include "core/core.hpp"
#include "action.hpp"
#include <gtkmm.h>

namespace horizon {

class ToolPopover : public Gtk::Popover {
public:
    ToolPopover(Gtk::Widget *parent);
    typedef sigc::signal<void, ToolID> type_signal_tool_activated;
    // type_signal_selected signal_selected() {return s_signal_selected;}
    type_signal_tool_activated signal_tool_activated()
    {
        return s_signal_tool_activated;
    }
    void set_can_begin(const std::map<ToolID, bool> &can_begin);
    void set_key_sequences(ToolID tool_id, const std::vector<KeySequence2> &seqs);

private:
    Gtk::SearchEntry *search_entry;
    class ListColumns : public Gtk::TreeModelColumnRecord {
    public:
        ListColumns()
        {
            Gtk::TreeModelColumnRecord::add(name);
            Gtk::TreeModelColumnRecord::add(tool_id);
            Gtk::TreeModelColumnRecord::add(can_begin);
            Gtk::TreeModelColumnRecord::add(keys);
        }
        Gtk::TreeModelColumn<Glib::ustring> name;
        Gtk::TreeModelColumn<ToolID> tool_id;
        Gtk::TreeModelColumn<bool> can_begin;
        Gtk::TreeModelColumn<Glib::ustring> keys;
    };
    ListColumns list_columns;
    Gtk::TreeView *view;
    Glib::RefPtr<Gtk::ListStore> store;
    Glib::RefPtr<Gtk::TreeModelFilter> store_filtered;
    void emit_tool_activated();
    type_signal_tool_activated s_signal_tool_activated;
    void on_show() override;
};
} // namespace horizon