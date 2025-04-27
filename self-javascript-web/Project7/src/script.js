let imgBox = document.getElementById('imgbox');
let qrimage = document.getElementById('QRimage');
let input = document.getElementById('inputQR');

function generatorQR(){
    qrimage.src = 'https://api.qrserver.com/v1/create-qr-code/?size=150x150&data=' + input.value;
    imgBox.style.display = "flex";
}