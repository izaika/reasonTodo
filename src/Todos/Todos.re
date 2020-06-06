[@bs.obj] external makeProps: unit => unit;

type todo = {
  id: string,
  title: string,
  isDone: bool,
};

let make = () => {
  Js.log(Utils.guid());

  let initialTodos: list(todo) = [
    {id: Utils.guid(), title: "Wake up", isDone: true},
  ];

  let (todos, setTodos) = React.useState(() => initialTodos);

  let listElements =
    todos
    |> List.map(todo => {
         <li key={todo.id}>
           {React.string(todo.title ++ " / " ++ todo.id)}
         </li>
       });

  <div>
    <ul> {React.array(Array.of_list(listElements))} </ul>
    <button> {React.string("Add todo")} </button>
  </div>;
};