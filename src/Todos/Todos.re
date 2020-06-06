[@bs.obj] external makeProps: unit => unit;

type todo = {
  id: string,
  title: string,
  isDone: bool,
};

let getNewTodo: unit => todo =
  () => {id: Utils.guid(), title: "", isDone: false};

let make = () => {
  let initialTodos: list(todo) = [getNewTodo()];

  let (todos, setTodos) = React.useState(() => initialTodos);

  let addTodo = () => setTodos(todos => List.append(todos, [getNewTodo()]));

  let listElements =
    todos
    |> List.map(todo => {
         <li key={todo.id}>
           {React.string(todo.title ++ " / " ++ todo.id)}
         </li>
       });

  <div>
    <ul> {React.array(Array.of_list(listElements))} </ul>
    <button onClick={_ => addTodo()}> {React.string("Add todo")} </button>
  </div>;
};