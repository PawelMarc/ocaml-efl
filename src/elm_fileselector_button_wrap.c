#include "include.h"

PREFIX value ml_elm_fileselector_button_add(value v_parent)
{
        Evas_Object* obj = elm_fileselector_button_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_filesselector_button_add");
        return (value) obj;
}

PREFIX value ml_elm_fileselector_button_window_title_set(
        value v_obj, value v_title)
{
        elm_fileselector_button_window_title_set((Evas_Object*) v_obj,
                String_val(v_title));
        return Val_unit;
}

PREFIX value ml_elm_fileselector_button_window_title_get(value v_obj)
{
        return copy_string(elm_fileselector_button_window_title_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_fileselector_button_window_size_set(
        value v_obj, value v_w, value v_h)
{
        elm_fileselector_button_window_size_set((Evas_Object*) v_obj,
                Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_fileselector_button_window_size_get(value v_obj)
{
        Evas_Coord w, h;
        elm_fileselector_button_window_size_get((Evas_Object*) v_obj, &w, &h);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(w));
        Store_field(v_r, 1, Val_int(h));
        return v_r;
}

PREFIX value ml_elm_fileselector_button_path_set(value v_obj, value v_path)
{
        elm_fileselector_button_path_set((Evas_Object*) v_obj,
                String_val(v_path));
        return Val_unit;
}

PREFIX value ml_elm_fileselector_button_path_get(value v_obj)
{
        return copy_string(elm_fileselector_button_path_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_fileselector_button_expandable_set(
        value v_obj, value v_flag)
{
        elm_fileselector_button_expandable_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_fileselector_button_expandable_get(value v_obj)
{
        return Val_bool(elm_fileselector_button_expandable_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_fileselector_button_folder_only_set(
        value v_obj, value v_flag)
{
        elm_fileselector_button_folder_only_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_fileselector_button_folder_only_get(value v_obj)
{
        return Val_bool(elm_fileselector_button_folder_only_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_fileselector_button_is_save_set(
        value v_obj, value v_flag)
{
        elm_fileselector_button_is_save_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_fileselector_button_is_save_get(value v_obj)
{
        return Val_bool(elm_fileselector_button_is_save_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_fileselector_button_inwin_mode_set(
        value v_obj, value v_flag)
{
        elm_fileselector_button_inwin_mode_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_fileselector_button_inwin_mode_get(value v_obj)
{
        return Val_bool(elm_fileselector_button_inwin_mode_get(
                (Evas_Object*) v_obj));
}

