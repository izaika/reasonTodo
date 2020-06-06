[@react.component]
let make = (~todo: Types.todo, ~toggleIsChecked: _ => unit) => {
  <div>
    <input
      onChange=toggleIsChecked
      id={"todo_" ++ todo.id}
      type_="checkbox"
      value={string_of_bool(todo.isDone)}
    />
    <input type_="text" value={todo.title} />
  </div>;
};