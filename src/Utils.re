let s4 = () => {
  let num = Js.Math.floor((1.0 +. Random.float(1.0)) *. 65536.0);
  let str = Js.Int.toStringWithRadix(num, ~radix=16);
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