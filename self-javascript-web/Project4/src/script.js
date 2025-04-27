const passwordBox = document.getElementById('password')
const lenght = 12;

const upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const lowerCase = "abcdefghijklmnopqrstuvwxyz";
const numbers = "0123456789";
const symbol = "@#$%^&*()_+~|}{[]></-=";

const allchars = upperCase + lowerCase + numbers + symbol;

function createPassword(){
    let password = "";
    password += upperCase[Math.floor(Math.random() * upperCase.length)];
    password += lowerCase[Math.floor(Math.random() * lowerCase.length)];
    password += numbers[Math.floor(Math.random() * numbers.length)];
    password += symbol[Math.floor(Math.random() * symbol.length)];

    while(lenght > password.length){
        password += allchars[Math.floor(Math.random() * allchars.length)];
    }
    passwordBox.value = password;
}

function copyToClipboard() {
    const passwordBox = document.getElementById('password');
    const password = passwordBox.value;

    // ใช้ Clipboard API ในการคัดลอกข้อความ
    navigator.clipboard.writeText(password).then(function() {
        console.log('Text copied to clipboard');
        // คุณสามารถแสดงข้อความแจ้งเตือนว่าคัดลอกสำเร็จได้ที่นี่
    }).catch(function(error) {
        console.error('Error copying text: ', error);
    });
}