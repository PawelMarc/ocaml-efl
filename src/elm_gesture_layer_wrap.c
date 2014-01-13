#include "include.h"

PREFIX inline Elm_Gesture_Type Elm_Gesture_Type_val(value v)
{
        switch(v) {
                case Val_n_taps: return ELM_GESTURE_N_TAPS;
                case Val_n_long_taps: return ELM_GESTURE_N_LONG_TAPS;
                case Val_n_double_taps: return ELM_GESTURE_N_DOUBLE_TAPS;
                case Val_n_triple_taps: return ELM_GESTURE_N_TRIPLE_TAPS;
                case Val_momentum: return ELM_GESTURE_MOMENTUM;
                case Val_n_lines: return ELM_GESTURE_N_LINES;
                case Val_n_flicks: return ELM_GESTURE_N_FLICKS;
                case Val_zoom: return ELM_GESTURE_ZOOM;
                case Val_rotate: return ELM_GESTURE_ROTATE;
                default: break;
        }
        caml_failwith("Elm_Gsture_Type_val");
        return ELM_GESTURE_N_TAPS;
}

PREFIX inline Elm_Gesture_State Elm_Gesture_State_val(value v)
{
        switch(v) {
                case Val_undefined: return ELM_GESTURE_STATE_UNDEFINED;
                case Val_start: return ELM_GESTURE_STATE_START;
                case Val_move: return ELM_GESTURE_STATE_MOVE;
                case Val_end: return ELM_GESTURE_STATE_END;
                case Val_abort: return ELM_GESTURE_STATE_ABORT;
                default: break;
        }
        caml_failwith("Elm_Gesture_State_val");
        return ELM_GESTURE_STATE_UNDEFINED;
}

PREFIX Evas_Event_Flags ml_Elm_Gesture_Event_Cb(void* data, void* event_info)
{
        value* v_fun = (value*) data;
        caml_callback(*v_fun, (value) event_info);
        return EVAS_EVENT_FLAG_ON_HOLD;
}

PREFIX value ml_elm_gesture_layer_cb_set(
        value v_obj, value v_type, value v_state, value v_cb)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_cb;
        caml_register_global_root(data);
        elm_gesture_layer_cb_set((Evas_Object*) v_obj,
                Elm_Gesture_Type_val(v_type), Elm_Gesture_State_val(v_state),
                ml_Elm_Gesture_Event_Cb, data);
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_hold_events_get(value v_obj)
{
        return Val_bool(elm_gesture_layer_hold_events_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gesture_layer_hold_events_set(value v_obj, value v_flag)
{
        elm_gesture_layer_hold_events_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_zoom_step_set(value v_obj, value v_step)
{
        elm_gesture_layer_zoom_step_set((Evas_Object*) v_obj,
                Double_val(v_step));
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_zoom_step_get(value v_obj)
{
        return copy_double(elm_gesture_layer_zoom_step_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gesture_layer_rotate_step_set(value v_obj, value v_step)
{
        elm_gesture_layer_rotate_step_set((Evas_Object*) v_obj,
                Double_val(v_step));
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_rotate_step_get(value v_obj)
{
        return copy_double(elm_gesture_layer_rotate_step_get(
                (Evas_Object*) v_obj));
}
