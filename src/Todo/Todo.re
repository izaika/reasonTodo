[@react.component]
let make =
    (
      ~todo: Types.todo,
      ~onCheckedChange: _ => unit,
      ~onTitleChange: (~title: string) => unit,
      ~onDeleteClick: _ => unit,
    ) => {
  let (title, setTitle) = React.useState(() => todo.title);

  <div>
    <input
      onChange=onCheckedChange
      id={"todo_" ++ todo.id}
      type_="checkbox"
      value={todo.isDone |> string_of_bool}
    />
    <input
      type_="text"
      value=title
      onChange={e => ReactEvent.Form.target(e)##value |> setTitle}
      onBlur={_ => onTitleChange(~title)}
    />
    <button onClick=onDeleteClick> {"Delete" |> React.string} </button>
  </div>;
};