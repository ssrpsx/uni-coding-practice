let switchtheme = document.getElementById('switch');
let boxes = document.querySelectorAll('.box');
let createicon = document.createElement('img');
let navbar = document.getElementsByClassName('narbar');
let text = document.getElementById('text');
let text1 = document.getElementById('text1');
let text2 = document.getElementById('text2');
let text3 = document.getElementById('text3');
let text4 = document.getElementById('text4');
let text5 = document.getElementById('text5');
let text6 = document.getElementById('text6');

switchtheme.onclick = function() {
    if (switchtheme.textContent == '1') {
        switchtheme.textContent = '2';
        createicon.src = "images/sun.png";
        switchtheme.appendChild(createicon)
        document.body.style.backgroundColor = "rgb(40, 40, 40)";
        navbar[0].style.backgroundColor = "rgb(20, 20, 20)";

        text.style.color = "white"
        text1.style.color = "white"
        text2.style.color = "white"
        text3.style.color = "white"
        text4.style.color = "white"
        text5.style.color = "white"
        text6.style.color = "black"
    } else {
        switchtheme.textContent = '1';
        createicon.src = "images/moon.png";
        switchtheme.appendChild(createicon)
        document.body.style.backgroundColor = "white";
        navbar[0].style.backgroundColor = "#f1f5f7";

        text.style.color = "black"
        text1.style.color = "black"
        text2.style.color = "black"
        text3.style.color = "black"
        text4.style.color = "black"
        text5.style.color = "black"
        text6.style.color = "black"
    }
    switchtheme.appendChild(createicon);

    boxes.forEach(function(box) {
        let innerBoxes = box.querySelectorAll('div');
        innerBoxes.forEach(function(innerBox) {
            if (switchtheme.textContent == 'โหมดสว่าง') {
                innerBox.style.backgroundColor = 'rgba(255, 255, 255, 0.4)';
            } else {
                innerBox.style.backgroundColor = 'rgba(0, 0, 0, 0.2)';
            }
        });
    });
}
