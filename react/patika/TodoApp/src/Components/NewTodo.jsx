import React, { useState } from "react";

function InputTodo({ todos, setTodos, toggleTodo }) {
  const [newTodo, setNewTodo] = useState("");

  function TodoSubmit(e) {
    e.preventDefault();

    if (newTodo.trim().length > 0) {
      setTodos((currentTodos) => {
        return [
          ...currentTodos,
          {
            id: crypto.randomUUID(),
            title: newTodo,
            completed: false,
            isEditing: false,
          },
        ];
      });
    } else {
      return alert("Please submit an valid input");
    }

    setNewTodo("");
  }

  return (
    <div>
      {" "}
      <header className="header">
        <h1>todos</h1>
        <form onSubmit={TodoSubmit}>
          <input
            className="new-todo"
            placeholder="What needs to be done?"
            value={newTodo}
            onChange={(e) => {
              setNewTodo(e.target.value);
            }}
            autoFocus
          />
        </form>
      </header>
    </div>
  );
}

export default InputTodo;
