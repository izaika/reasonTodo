[@bs.obj] external makeProps: unit => unit;

let getNewTodo: unit => Types.todo =
  () => {id: Utils.guid(), title: "", isDone: false};

let toggleIsDone = (id: string, todo: Types.todo) =>
  todo.id == id ? {...todo, isDone: !todo.isDone} : todo;

let changeTitle = (id: string, title: string, todo: Types.todo) =>
  todo.id == id ? {...todo, title} : todo;

let todoToElement =
    (
      onCheckedChange: (~id: string) => unit,
      onTitleChange: (~id: string, ~title: string) => unit,
      todo: Types.todo,
    ) =>
  <li key={todo.id}>
    <Todo
      todo
      onCheckedChange={_ => onCheckedChange(~id=todo.id)}
      onTitleChange={value => onTitleChange(~id=todo.id, ~title=value)}
    />
  </li>;

let make = () => {
  let (todos, setTodos) = React.useState(() => [getNewTodo()]);

  let addTodo = () => setTodos(todos => List.append(todos, [getNewTodo()]));

  let onCheckedChange = (~id: string) =>
    id |> toggleIsDone |> List.map |> setTodos;

  let onTitleChange = (~id: string, ~title: string) =>
    title |> changeTitle(id) |> List.map |> setTodos;

  let todosToElements: list(Types.todo) => list(React.element) =
    todoToElement(onCheckedChange, onTitleChange) |> List.map;

  <div>
    <ul> {todos |> todosToElements |> Array.of_list |> React.array} </ul>
    <button onClick={_ => addTodo()}> {"Add todo" |> React.string} </button>
  </div>;
};