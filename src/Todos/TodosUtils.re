let getNewTodo: unit => Types.todo =
  () => {id: Utils.guid(), title: "", isDone: false};

let toggleIsDone = (id: string, todo: Types.todo) =>
  todo.id === id ? {...todo, isDone: !todo.isDone} : todo;

let changeTitle = (id: string, title: string, todo: Types.todo) =>
  todo.id === id ? {...todo, title} : todo;

let filterTodo = (id: string, todo: Types.todo) => todo.id !== id;