open Efl

let retval = ref (-1)

let win_del _ =
  retval := -1;
  Elm.exit ()

let on_ok _ =
  retval := 0;
  Elm.exit ()

let on_cancel _ =
  retval := -1;
  Elm.exit ()

let () =
  Elm.init ();
 
  let text =
    if Array.length Sys.argv > 1 then Sys.argv.(1) else "No text provided" in

  let win = Elm_win.add "dialog" `basic in
  Elm_win.title_set win "Dialog";
  Evas_object_smart.callback_add win Elm_sig.delete_request win_del;

  let bg = Elm_bg.add win in
  Evas_object.size_hint_set bg [`weight0];
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let bx = Elm_box.add win in
  Evas_object.size_hint_set bx [`weight0];
  Elm_win.resize_object_add win bx;
  Evas_object.show bx;

  let fr = Elm_frame.add win in
  let (_ : bool) = Elm_object.style_set fr "pad_large" in
  Evas_object.size_hint_set fr [`weight0; `fill];
  Elm_box.pack_end bx fr;
  Evas_object.show fr;

  let lb = Elm_label.add win in
  Elm_object.text_set lb text;
  Elm_object.content_set fr lb;
  Evas_object.show lb;

  let fr0 = Elm_frame.add win in
  let (_ : bool) = Elm_object.style_set fr0 "outdent_bottom" in
  Evas_object.size_hint_set fr0 [`weight0; `fill];
  Elm_box.pack_end bx fr0;
  Evas_object.show fr0;

  let fr = Elm_frame.add win in
  let (_ : bool) = Elm_object.style_set fr "pad_medium" in
  Elm_object.content_set fr0 fr;
  Evas_object.show fr;

  let bx2 = Elm_box.add win in
  Elm_box.horizontal_set bx2 true;
  Elm_box.homogeneous_set bx2 true;
  Elm_object.content_set fr bx2;
  Evas_object.show bx2;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "OK";
  Evas_object.size_hint_set bt [`expand; `fill];
  Elm_box.pack_end bx2 bt;
  Evas_object.show bt;
  Evas_object_smart.callback_add bt Elm_sig.clicked on_ok;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Cancel";
  Evas_object.size_hint_set bt [`expand; `fill];
  Elm_box.pack_end bx2 bt;
  Evas_object.show bt;
  Evas_object_smart.callback_add bt Elm_sig.clicked on_cancel;

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ();
  exit !retval
