[@bs.obj] external makeProps: unit => unit;

let getNewTodo: unit => Types.todo =
  () => {id: Utils.guid(), title: "", isDone: false};

let toggleIsDone = (id: string, todo: Types.todo) =>
  todo.id === id ? {...todo, isDone: !todo.isDone} : todo;

let changeTitle = (id: string, title: string, todo: Types.todo) =>
  todo.id === id ? {...todo, title} : todo;

let filterTodo = (id: string, todo: Types.todo) => todo.id !== id;

let todoToElement =
    (
      onCheckedChange: (~id: string) => unit,
      onTitleChange: (~id: string, ~title: string) => unit,
      onDeleteClick: (~id: string) => unit,
      todo: Types.todo,
    ) => {
  let id = todo.id;

  <li key=id>
    <Todo
      todo
      onCheckedChange={_ => onCheckedChange(~id)}
      onTitleChange={(~title) => onTitleChange(~id, ~title)}
      onDeleteClick={_ => onDeleteClick(~id)}
    />
  </li>;
};

let make = () => {
  let (todos, setTodos) = React.useState(() => [getNewTodo()]);

  let addTodo = () => setTodos(todos => List.append(todos, [getNewTodo()]));

  let onCheckedChange = (~id: string) =>
    id |> toggleIsDone |> List.map |> setTodos;

  let onTitleChange = (~id: string, ~title: string) =>
    changeTitle(id, title) |> List.map |> setTodos;

  let onDeleteClick = (~id: string) =>
    id |> filterTodo |> List.filter |> setTodos;

  let todosToElements: list(Types.todo) => list(React.element) =
    todoToElement(onCheckedChange, onTitleChange, onDeleteClick) |> List.map;

  <div>
    <ul> {todos |> todosToElements |> Array.of_list |> React.array} </ul>
    <button onClick={_ => addTodo()}> {"Add todo" |> React.string} </button>
  </div>;
};