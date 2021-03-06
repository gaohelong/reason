f(.);

[@attr] f(.);

[@bs] f();

f(. a, b, c);

[@attr] f(. a, b, c);

let f = (. a, b) => a + b;

let f = [@attr] (. a, b) => a + b;

let f = [@bs] (. a, b) => a + b;

let f = ("hello",  (. b, c) => b + c);

let f = ("hello",  [@attr] (. b, c) => b + c);

let f = ("hello",  [@bs] (. b, c) => b + c);

let obj: tesla = {
  pub drive = (. speed, safe) => (speed, safe);
  pub drive2 = [@attr] (. speed, safe) => (speed, safe);
  pub park = (.) => ();
  pub park2 = [@attr] (.) => ();
};

type f = (. int, int) => int;

type f = [@attr] (. int, int) => int;

type f = [@bs] ((int, int) => int);

type z = [@bs] unit => unit;

type z = [@attr] [@bs] unit => unit;

type z = (. unit) => unit;

type tesla = {.
  drive: (. int, int) => int
};

class type _rect =
  [@bs]
  {
    [@bs.set] pub height: int;
    [@bs.set] pub width: int;
    pub draw: unit => unit
  };

class type _rect = {.
  [@bs.set]
  pub height: int;
  [@bs.set]
  pub width: int;
  pub draw: unit => unit
};

funWithCb("text", (.) => doStuff());

funWithCb("text", (. test) => doStuff());

funWithCb("text", [@attr] (. arg) => doStuff());

test(~desc="my test", (.) => {
  let x = a + b;
  let y = z + c;
  x + y;
});

test(~desc="my test", [@attr] (. a, b, c) => {
  let x = a + b;
  let y = z + c;
  x + y;
});

Thing.map(
  ~a=?foo,
  ~b=?bar,
  ~c=?baz,
  ~d=?foo2,
  ~e=?bakjlksjdf,
  ~f=?okokokok,
  ~cb=[@attr] (. abc, z) => {
    let x = 1;
    MyModuleBlah.toList(x, argument);
  }
);

type f = int => (. int) => unit;

type f = (int, . int) => unit;
