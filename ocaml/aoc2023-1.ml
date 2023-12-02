let read_file_lines file =
  let ic = open_in file in
  try
    let rec read_file_iter ic lines =
      try
        read_file_iter ic (List.append lines [input_line ic])
      with End_of_file ->
        close_in ic;
        lines
      in read_file_iter ic [];
  with e -> 
    close_in_noerr ic;
    raise e

let is_char_number c = 
  let code = Char.code c in
  code >= 48 && code <= 57

let parse_calibration_value line =
  let number_string = String.fold_left (fun a c -> if is_char_number c then a ^ (Char.escaped c) else a) "" line in
  (String.make 1 (String.get number_string 0)) ^ (String.make 1 (String.get number_string ((String.length number_string) - 1)));;

let () = Printf.printf "%d\n" (List.fold_left (fun a c -> a + c) 0 (List.map (fun x -> int_of_string (parse_calibration_value x)) (read_file "aoc2023-1.input.txt")));;
