[@react.component]
let make = () => {
  <div className=AppCss.container>
    <h1 className=AppCss.h1> {React.string("Hello world!")} </h1>
    <Todos />
  </div>;
};