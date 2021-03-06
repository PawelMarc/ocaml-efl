#include "include.h"

PREFIX inline Eina_Bool Eina_Bool_val(value v) {
        return (Eina_Bool) Int_val(v);
}

PREFIX inline value Val_Eina_Bool(Eina_Bool b) {
        return Val_int (b);
}

PREFIX inline value copy_Eina_List_string(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal3(v, v1, v_s);
        Eina_List* it;
        char* s;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, s) {
                v1 = v;
                v_s = copy_string(s);
                v = caml_alloc(2, 0);
                Store_field(v, 0, v_s);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

PREFIX inline Eina_List* Eina_List_string_val(value v_list)
{
        Eina_List* list = NULL;
        value v;
        while(v != Val_int(0)) {
                list = eina_list_append(list, String_val(Field(v, 0)));
                v = Field(v, 1);
        }
        return list;
}

PREFIX inline value copy_Eina_List_Evas_Object(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal2(v, v1);
        Eina_List* it;
        Evas_Object* obj;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, obj) {
                v1 = v;
                v = caml_alloc(2, 0);
                Store_field(v, 0, (value) obj);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

PREFIX inline Eina_List* Eina_List_Evas_Object_val(value v_list)
{
        Eina_List* list = NULL;
        value v;
        while(v != Val_int(0)) {
                list = eina_list_append(list, (Evas_Object*) Field(v, 0));
                v = Field(v, 1);
        }
        return list;
}

PREFIX inline value copy_Eina_List_Elm_Object_Item(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal2(v, v1);
        Eina_List* it;
        Elm_Object_Item* item;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, item) {
                v1 = v;
                v = caml_alloc(2, 0);
                Store_field(v, 0, (value) item);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

