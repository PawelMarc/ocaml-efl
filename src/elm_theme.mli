type t = Elm.theme

val _new : unit -> t

val free : t -> unit

val copy : t -> t -> unit

val ref_set : t -> t option -> unit

val ref_get : t -> t option

val default_get : unit -> t

val overlay_add : ?th:t -> string -> unit

val overlay_del : ?th:t -> string -> unit

val overlay_list_get : t -> string list

val list_item_path_get : string -> (string * bool) option

