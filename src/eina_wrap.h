#ifndef EINA_H
#define EINA_H

#include "include.h"

PREFIX inline Eina_Bool Eina_Bool_val(value v);
PREFIX inline value Val_Eina_Bool(Eina_Bool b);

PREFIX inline value copy_Eina_List_string(const Eina_List* list);
PREFIX inline Eina_List* Eina_List_string_val(value v);

PREFIX inline value copy_Eina_List_Evas_Object(const Eina_List* list);
PREFIX inline Eina_List* Eina_List_Evas_Object_val(value v_list);

PREFIX inline value copy_Eina_List_Elm_Object_Item(const Eina_List* list);

#endif
