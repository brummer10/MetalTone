
#define CONTROLS 8

#define GUI_ELEMENTS 0

#define TAB_ELEMENTS 0


#define PLUGIN_UI_URI "https://github.com/brummer10/MetalTone_ui"


#include "lv2_plugin.h"
#include "xresources.h"

void set_costum_theme(Xputty *main) {
    main->color_scheme->normal = (Colors) {
         /* cairo    / r  / g  / b  / a  /  */
        .fg =       { 0.850, 0.850, 0.850, 1.000},
        .bg =       { 0.100, 0.100, 0.100, 1.000},
        .base =     { 0.000, 0.000, 0.000, 1.000},
        .text =     { 0.679, 0.424, 0.263, 1.000},
        .shadow =   { 0.000, 0.000, 0.000, 0.200},
        .frame =    { 0.000, 0.000, 0.000, 1.000},
        .light =    { 0.100, 0.100, 0.100, 1.000}
    };

    main->color_scheme->prelight = (Colors) {
         /* cairo    / r  / g  / b  / a  /  */
        .fg =       { 1.000, 0.000, 1.000, 1.000},
        .bg =       { 0.250, 0.250, 0.250, 1.000},
        .base =     { 0.300, 0.300, 0.300, 1.000},
        .text =     { 1.000, 1.000, 1.000, 1.000},
        .shadow =   { 0.100, 0.100, 0.100, 0.400},
        .frame =    { 0.300, 0.300, 0.300, 1.000},
        .light =    { 0.300, 0.300, 0.300, 1.000}
    };

    main->color_scheme->selected = (Colors) {
         /* cairo    / r  / g  / b  / a  /  */
        .fg =       { 0.900, 0.900, 0.900, 1.000},
        .bg =       { 0.200, 0.200, 0.200, 1.000},
        .base =     { 0.500, 0.180, 0.180, 1.000},
        .text =     { 1.000, 1.000, 1.000, 1.000},
        .shadow =   { 0.800, 0.180, 0.180, 0.200},
        .frame =    { 0.500, 0.180, 0.180, 1.000},
        .light =    { 0.500, 0.180, 0.180, 1.000}
    };

    main->color_scheme->active = (Colors) {
         /* cairo    / r  / g  / b  / a  /  */
        .fg =       { 0.000, 1.000, 1.000, 1.000},
        .bg =       { 0.000, 0.000, 0.000, 1.000},
        .base =     { 0.180, 0.380, 0.380, 1.000},
        .text =     { 0.750, 0.750, 0.750, 1.000},
        .shadow =   { 0.180, 0.380, 0.380, 0.500},
        .frame =    { 0.180, 0.380, 0.380, 1.000},
        .light =    { 0.180, 0.380, 0.380, 1.000}
    };

    main->color_scheme->insensitive = (Colors) {
         /* cairo    / r  / g  / b  / a  /  */
        .fg =       { 0.850, 0.850, 0.850, 0.500},
        .bg =       { 0.100, 0.100, 0.100, 0.500},
        .base =     { 0.000, 0.000, 0.000, 0.500},
        .text =     { 0.900, 0.900, 0.900, 0.500},
        .shadow =   { 0.000, 0.000, 0.000, 0.100},
        .frame =    { 0.000, 0.000, 0.000, 0.500},
        .light =    { 0.100, 0.100, 0.100, 0.500}
    };
}

#include "lv2_plugin.cc"



void plugin_value_changed(X11_UI *ui, Widget_t *w, PortIndex index) {
    // do special stuff when needed
    if (index == 2) adj_set_value(ui->widget[7]->adj, adj_get_value(ui->widget[0]->adj));
}

void plugin_set_window_size(int *w,int *h,const char * plugin_uri, float scale) {
    (*w) = 274 * scale; //set initial width of main window
    (*h) = 530 * scale; //set initial height of main window
}

const char* plugin_set_name() {
    return "MetalTone"; //set plugin name to display on UI
}

void plugin_create_controller_widgets(X11_UI *ui, const char * plugin_uri, float scale) {
    set_costum_theme(&ui->main);
    widget_get_png(ui->win, LDVAR(pedal_png));
    ui->widget[0] = add_lv2_image_toggle (ui->widget[0], ui->win, 2, "Bypass", ui, 8,  312, 260 * scale, 180 * scale);
    widget_get_png(ui->widget[0], LDVAR(switch_png));

    ui->widget[1] = add_lv2_knob (ui->widget[1], ui->win, 3, "Dist", ui, 25,  50, 60 * scale, 70 * scale);
    widget_get_png(ui->widget[1], LDVAR(knob_png));
    set_adjustment(ui->widget[1]->adj, 0.000, 0.000, 0.000, 1.000, 0.010, CL_CONTINUOS);

    ui->widget[2] = add_lv2_knob (ui->widget[2], ui->win, 5, "Level", ui, 205,  50, 60 * scale, 70 * scale);
    widget_get_surface_ptr(ui->widget[2], ui->widget[1]);
    set_adjustment(ui->widget[2]->adj, 0.300, 0.300, 0.000, 1.000, 0.010, CL_CONTINUOS);

    ui->widget[3] = add_lv2_knob (ui->widget[3], ui->win, 6, "Low", ui, 85,  15, 60 * scale, 70 * scale);
    widget_get_surface_ptr(ui->widget[3], ui->widget[1]);
    set_adjustment(ui->widget[3]->adj, 0.500, 0.500, 0.000, 1.000, 0.010, CL_CONTINUOS);

    ui->widget[4] = add_lv2_knob (ui->widget[4], ui->win, 4, "High", ui, 145,  15, 60 * scale, 70 * scale);
    widget_get_surface_ptr(ui->widget[4], ui->widget[1]);
    set_adjustment(ui->widget[4]->adj, 0.500, 0.500, 0.000, 1.000, 0.010, CL_CONTINUOS);

    ui->widget[5] = add_lv2_knob (ui->widget[5], ui->win, 7, "MidFreq", ui, 85,  95, 60 * scale, 70 * scale);
    widget_get_surface_ptr(ui->widget[5], ui->widget[1]);
    set_adjustment(ui->widget[5]->adj, 0.500, 0.500, 0.000, 1.000, 0.010, CL_CONTINUOS);

    ui->widget[6] = add_lv2_knob (ui->widget[6], ui->win, 8, "Middle", ui, 145,  95, 60 * scale, 70 * scale);
    widget_get_surface_ptr(ui->widget[6], ui->widget[1]);
    set_adjustment(ui->widget[6]->adj, 0.500, 0.500, 0.000, 1.000, 0.010, CL_CONTINUOS);

    ui->widget[7] = add_lv2_image_switch (ui->widget[7], ui->win, 2, "", ui, 115,  205, 44 * scale, 44 * scale);
    widget_get_png(ui->widget[7], LDVAR(led_red_png));

}

void plugin_cleanup(X11_UI *ui) {
    // clean up used sources when needed
}


void plugin_port_event(LV2UI_Handle handle, uint32_t port_index,
                        uint32_t buffer_size, uint32_t format,
                        const void * buffer) {
    // port value change message from host
    // do special stuff when needed
}

