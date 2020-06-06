[@bs.obj] external makeProps: unit => unit;

let getNewTodo: unit => Types.todo =
  () => {id: Utils.guid(), title: "", isDone: false};

let make = () => {
  let initialTodos: array(Types.todo) = [|getNewTodo()|];

  let (todos, setTodos) = React.useState(() => initialTodos);

  let addTodo = () =>
    setTodos(todos => Array.append(todos, [|getNewTodo()|]));

  let toggleIsChecked = (index: int) => {
    setTodos(todos => {
      let todo = todos[index];
      todos[index] = {...todo, isDone: !todo.isDone};
      todos;
    });
  };

  let listElements =
    Array.mapi(
      (index, todo: Types.todo) => {
        <li key={todo.id}>
          <Todo todo toggleIsChecked={_ => toggleIsChecked(index)} />
        </li>
      },
      todos,
    );

  <div>
    <ul> {React.array(listElements)} </ul>
    <button onClick={_ => addTodo()}> {React.string("Add todo")} </button>
  </div>;
};