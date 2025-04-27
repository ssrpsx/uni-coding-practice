let icon = document.getElementById('icon');
let pass = document.getElementById('password');

icon.onclick = function(){
    if(pass.type == 'password'){
        pass.type = 'text';
        icon.src = 'images/eye-open.png';
        setTimeout(() => {
            pass.type = 'password';
            icon.src = 'images/eye-close.png';
        }, 1000);
    }
    else{
        pass.type = 'password';
        icon.src = 'images/eye-close.png'
    }
}