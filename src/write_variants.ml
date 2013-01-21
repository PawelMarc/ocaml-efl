open Printf

external get_hash_value : string -> string = "ml_get_hash_value"

let f x y = printf "#define %s %s\n" x (get_hash_value y)

let g x = f (sprintf "Val_%s" x) x

let () =
  g "allcharacter";
  g "alpha";
  g "alphabet";
  g "auto";
  g "automatic";
  g "basic";
  g "bottom";
  g "bottom_left";
  g "bottom_right";
  g "center";
  g "char";
  g "close";
  g "combo";
  g "default";
  g "desktop";
  g "dialog_basic";
  g "dnd";
  g "dock";
  f "Val_done" "_done";
  g "dropdown_menu";
  g "email";
  g "file";
  g "focus_back";
  g "focus_forward";
  g "focus_home";
  g "go";
  g "hex";
  g "hide";
  g "host";
  g "inlined_image";
  g "invalid";
  g "ip";
  g "j2me";
  g "join";
  g "keypad";
  g "last";
  g "last_window_closed";
  g "left";
  g "login";
  g "markup";
  g "markup_utf8";
  g "menu";
  g "mixed";
  g "month";
  g "next";
  g "no_image";
  g "none";
  g "normal";
  g "notification";
  g "number";
  g "numberonly";
  g "numeric";
  g "off";
  g "on";
  g "opacity_unknown";
  g "opaque";
  g "password";
  g "phone_number";
  g "phonenumber";
  g "pin";
  g "plain_utf8";
  g "plaintext";
  g "popup_menu";
  g "quit";
  g "right";
  g "search";
  g "send";
  g "sentence";
  g "show";
  g "splash";
  g "socket_image";
  g "standard";
  g "terminal";
  g "toolbar";
  g "tooltip";
  g "top";
  g "top_left";
  g "top_right";
  g "translucent";
  g "transparent";
  g "unknown";
  g "url";
  g "utility";
  g "word";
  flush stdout