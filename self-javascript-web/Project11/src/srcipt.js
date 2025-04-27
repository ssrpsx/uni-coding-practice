let progress = document.getElementById('progress');
let song = document.getElementById('song');
let ctrlIcon = document.getElementById('ctrlIcon');
let MusicName = document.getElementById('MusicName');
let artist = document.getElementById('artist');
let image = document.getElementById('image');

song.onloadedmetadata = function(){
    progress.max = song.duration;
    progress.value = song.currentTime;
    song.volume = 0.5;
}

document.addEventListener('DOMContentLoaded', function() {
    showTask();
    if(MusicName.innerHTML == "ความน่าจะเป็นเท่ากับสูญ"){
        artist.innerHTML = "AYLA's"
        image.src = "Images/Profile.jpg"
        song.src = "audio/audio1.mp3"
    }
    else{
        artist.innerHTML = "Tilly Birds"
        image.src = "Images/Profile2.jpg"
        song.src = "audio/audio2.mp3"
    }
});

function PlayPause(){
    if(ctrlIcon.classList.contains('fa-pause')){
        song.pause();
        ctrlIcon.classList.remove('fa-pause')
        ctrlIcon.classList.add('fa-play')
    }
    else{
        song.play();
        ctrlIcon.classList.remove('fa-play')
        ctrlIcon.classList.add('fa-pause')
    }
}

if(song.play()){
    setInterval(()=>{
        progress.value = song.currentTime;
    },1000);
}

progress.onchange = function(){
    song.play();
    song.currentTime = progress.value;
    ctrlIcon.classList.add('fa-pause')
    ctrlIcon.classList.remove('fa-play')
}

function updatestore(){
    localStorage.setItem('Name', MusicName.innerHTML);
}

function showTask(){
    if(localStorage.getItem('Name')){
        MusicName.innerHTML = localStorage.getItem('Name');
    }
}

function skip(){
    if(MusicName.innerHTML == "ความน่าจะเป็นเท่ากับสูญ"){
        MusicName.innerHTML = "คิด(แต่ไม่)ถึง"
        artist.innerHTML = "Tilly Birds"
        image.src = "Images/Profile2.jpg"
        song.src = "audio/audio2.mp3"
        song.play();
        ctrlIcon.classList.add('fa-pause')
        ctrlIcon.classList.remove('fa-play')
        updatestore();
    }
    else{
        MusicName.innerHTML = "ความน่าจะเป็นเท่ากับสูญ"
        artist.innerHTML = "AYLA's"
        image.src = "Images/Profile.jpg"
        song.src = "audio/audio1.mp3"
        song.play();
        ctrlIcon.classList.add('fa-pause')
        ctrlIcon.classList.remove('fa-play')
        updatestore();
    }
}

function Oop(){
    alert('Decorative Only ><')
}