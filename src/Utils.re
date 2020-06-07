let s4 = () => {
  let num = Js.Math.floor((1.0 +. Js.Math.random()) *. 65536.0);
  let str = num |> Js.Int.toStringWithRadix(~radix=16);
  String.sub(str, 0, 5);
};

let guid = (): string => {
  s4()
  ++ s4()
  ++ "-"
  ++ s4()
  ++ "-"
  ++ s4()
  ++ "-"
  ++ s4()
  ++ "-"
  ++ s4()
  ++ s4()
  ++ s4();
};