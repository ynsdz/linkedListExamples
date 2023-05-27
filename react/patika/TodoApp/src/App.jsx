import "./App.css";
import NewTodo from "./Components/NewTodo";
import InputTodo from "./Components/TodoList";
import TodoFooter from "./Components/TodoFooter";
import { useEffect, useState } from "react";
function App() {
  const [todos, setTodos] = useState(() => {
    if (!localStorage.getItem("todos")) return [];

    return JSON.parse(localStorage.getItem("todos"));
  });
  useEffect(() => {
    localStorage.setItem("todos", JSON.stringify(todos));
  }, [todos]);

  return (
    <>
      <section className="todoapp">
        <NewTodo todos={todos} setTodos={setTodos} />
        <InputTodo todos={todos} setTodos={setTodos} />
        <TodoFooter todos={todos} setTodos={setTodos} />
      </section>
    </>
  );
}

export default App;
