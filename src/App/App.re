[@react.component]
let make = () => {
  <div className=AppCss.container>
    <h1 className=AppCss.h1> {"State Todos" |> React.string} </h1>
    <Todos />
  </div>;
};