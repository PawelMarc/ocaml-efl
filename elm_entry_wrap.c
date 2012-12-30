#include "include.h"

PREFIX value ml_elm_entry_add(value v_parent)
{
        Evas_Object* entry = elm_entry_add((Evas_Object*) v_parent);
        if(entry == NULL) caml_failwith("ml_elm_entry_add");
        return (value) entry;
}

PREFIX value ml_elm_entry_style_user_push(value v_obj, value v_style)
{
        elm_entry_text_style_user_push((Evas_Object*) v_obj,
                (const char*) String_val(v_style));
        return Val_unit;
}

PREFIX value ml_elm_entry_style_user_pop(value v_obj)
{
        elm_entry_text_style_user_pop((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_style_user_peek(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        char* text = (char*) elm_entry_text_style_user_peek(
                (Evas_Object*) v_obj);
        if(text == NULL) return Val_int(0);
        v = caml_alloc(1, 0);
        Store_field(v, 0, copy_string(text));
        CAMLreturn(v);
}

