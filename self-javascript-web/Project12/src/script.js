let lists = document.getElementsByClassName('list');
let rightbox = document.getElementById('right');
let leftbox = document.getElementById('left');
let selected = null; // Store selected element outside the loop

for (list of lists) {
  list.addEventListener('dragstart', function (e) {
    selected = e.target;
  });
}

rightbox.addEventListener('dragover', function (e) {
    e.preventDefault();
});

rightbox.addEventListener('drop', function (e) {
  if (selected) {
    rightbox.appendChild(selected);
    selected = null;
  }
});

leftbox.addEventListener('dragover', function (e) {
  e.preventDefault();
});

leftbox.addEventListener('drop', function (e) {
  if (selected) {
    leftbox.appendChild(selected);
    selected = null;
  }
});
