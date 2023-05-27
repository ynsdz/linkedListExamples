import React from "react";

function TodoList({ todos, setTodos, destroyItem, toggleTodo }) {
  function deleteItem(id) {
    setTodos((todos) => {
      return todos.filter((todo) => todo.id !== id);
    });
  }

  function toggleTodo(id, completed) {
    setTodos((todos) => {
      return todos.map((todo) => {
        if (todo.id === id) {
          return { ...todo, completed };
        }
        return todo;
      });
    });
  }

  // function editTodo(id) {
  //   // setTodos(todos.map(todo=>todo.id ===id ? {...todo, }))
  // }
  return (
    <div>
      <section className="main">
        <input className="toggle-all" type="checkbox" />
        <label htmlFor="toggle-all">Mark all as complete</label>

        <ul className="todo-list">
          {todos.map((todo) => {
            return (
              <li key={todo.id}>
                <div className="view" mv-multiple="todo">
                  <input
                    className="toggle"
                    type="checkbox"
                    checked={todo.completed}
                    onChange={(e) => toggleTodo(todo.id, e.target.checked)}
                  />
                  <label>{todo.title}</label>
                  <button
                    className="destroy"
                    onClick={(e) => {
                      deleteItem(todo.id);
                    }}
                  ></button>
                </div>
              </li>
            );
          })}
        </ul>
      </section>
    </div>
  );
}

export default TodoList;
