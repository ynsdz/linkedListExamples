import React from "react";

function TodoFooter({ todos }) {
  function handleLeftItem() {
    let sayac = 0;
    todos.map((todo, i = 0) => !todo.completed && sayac++);
    return sayac;
  }
  function activeButton() {
    console.log("test");
  }
  return (
    <div>
      <footer className="footer">
        <span className="todo-count">
          <strong>{handleLeftItem()} </strong>
          items left
        </span>

        <ul className="filters">
          <li>
            <a href="#/" className="selected">
              All
            </a>
          </li>
          <li>
            <a href="#/" onClick={() => activeButton()}>
              Active
            </a>
          </li>
          <li>
            <a href="#/">Completed</a>
          </li>
        </ul>

        <button className="clear-completed">Clear completed</button>
      </footer>
    </div>
  );
}

export default TodoFooter;
