const apikey = "ede2669a996554bf763a8eed267931d3";
const apiurl = "https://api.openweathermap.org/data/2.5/weather?&units=metric&q=";

const searchbox = document.getElementById('searchbox');
const searchbtn = document.getElementById('searchbtn');
const weathericon = document.getElementById('weathericon');

async function check(city){
    const response = await fetch(apiurl + city +'&appid=' + apikey);
    var data = await response.json();

    console.log(data);

    document.querySelector('.city').innerHTML = data.name
    document.querySelector('.temp').innerHTML = Math.round(data.main.temp) + "°C"
    document.querySelector('.humidity').innerHTML = data.main.humidity + "%"
    document.querySelector('.wind').innerHTML = data.wind.speed + " km/h"

    if(data.weather[0].main == "Clouds"){
        weathericon.src = "images/clouds.png";
    }
    else if(data.weather[0].main == "Clear"){
        weathericon.src = "images/clear.png";
    }
    else if(data.weather[0].main == "Rain"){
        weathericon.src = "images/rain.png";
    }
    else if(data.weather[0].main == "Drizzle"){
        weathericon.src = "images/drizzle.png";
    }
    else if(data.weather[0].main == "Mist"){
        weathericon.src = "images/mist.png";
    }
}

searchbtn.addEventListener("click", ()=>{
    check(searchbox.value);
})