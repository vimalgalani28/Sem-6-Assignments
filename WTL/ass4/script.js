let string = "";
const ele = document.querySelector(".view-container")
ele.textContent = string;

const clearText = (e) => {
  string= "";
  ele.textContent = string;
}

const handleClick = (synmbol) => {
  string = string.concat(synmbol);
  ele.textContent = string
}

const calculate = () => {
  if(string.length === 0) {
    return;
  }
  if(string.startsWith("*") || string.startsWith("/")) {
    alert("Invalid Input");
    return;
  }
  const result = eval(string);
  if(result === Infinity) {
    alert("Infinity Error")
  } else {
    string = result.toString();
    ele.textContent = string;
  }
}
