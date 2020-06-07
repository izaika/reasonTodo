[@react.component]
let make =
    (
      ~todo: Types.todo,
      ~onCheckedChange: _ => unit,
      ~onTitleChange: (~value: string) => unit,
    ) => {
  let (title, setTitle) = React.useState(() => todo.title);

  <div>
    <input
      onChange=onCheckedChange
      id={"todo_" ++ todo.id}
      type_="checkbox"
      value={string_of_bool(todo.isDone)}
    />
    <input
      type_="text"
      value=title
      onChange={e => setTitle(ReactEvent.Form.target(e)##value)}
      onBlur={_ => onTitleChange(~value=title)}
    />
  </div>;
};