[@bs.obj] external makeProps: unit => unit;

let getNewTodo: unit => Types.todo =
  () => {id: Utils.guid(), title: "", isDone: false};

let make = () => {
  let initialTodos: list(Types.todo) = [getNewTodo()];

  let (todos, setTodos) = React.useState(() => initialTodos);

  React.useEffect1(_ => Some(() => Js.log(todos)), [|todos|]);

  let addTodo = () => setTodos(todos => List.append(todos, [getNewTodo()]));

  let onCheckedChange = (id: string) =>
    setTodos(
      List.map((todo: Types.todo) =>
        todo.id == id ? {...todo, isDone: !todo.isDone} : todo
      ),
    );

  let onTitleChange = (id: string, title: string) =>
    setTodos(
      List.map((todo: Types.todo) =>
        todo.id == id ? {...todo, title} : todo
      ),
    );

  let listElements =
    todos
    |> List.map((todo: Types.todo) =>
         <li key={todo.id}>
           <Todo
             todo
             onCheckedChange={_ => onCheckedChange(todo.id)}
             onTitleChange={(~value) => onTitleChange(todo.id, value)}
           />
         </li>
       );

  <div>
    <ul> {React.array(Array.of_list(listElements))} </ul>
    <button onClick={_ => addTodo()}> {React.string("Add todo")} </button>
  </div>;
};