const questions = [
    {
        question : "ACS มีอะไร",
        answers: [
            { text: "มีเพื่อนๆพี่ๆและอาจารย์ที่น่ารัก", correct: true},
            { text: "มีใจคอลมาได้ตลอด by ACS", correct: false},
            { text: "มีเวลานอนก็ดีแล้ว", correct: false},
            { text: "มี่มีมี่มีมี่มีมี เพลง: Mi Mi Mi BaBy", correct: false},
        ]
    },
    {
        question : "ไอนุต มีแฟนมาแล้วกี่คน? ><",
        answers: [
            { text: "3 คน", correct: false},
            { text: "5 คน", correct: true},
            { text: "7 คน", correct: false},
            { text: "12 คน", correct: false},
        ]
    },
    {
        question : "โซดา ชอบกินอะไร",
        answers: [
            { text: "หมีย่าง", correct: false},
            { text: "กินหมา", correct: false},
            { text: "กระเพราหมูกรอบ", correct: false},
            { text: "โซจู (ขอกระดกขวด)", correct: true},
        ]
    },
    {
        question : "ทรงผมของนุต คืออะไร",
        answers: [
            { text: "ทรงจุกฮ้าบบ", correct: false},
            { text: "ทรงมะฮอบ", correct: false},
            { text: "ทรงพระเจริญ", correct: false},
            { text: "ทรงหัวโล้น", correct: true},
        ]
    },
    {
        question : "โซเดียมคลอไรด์ >>",
        answers: [
            { text: "เดียวดาย call me", correct: true},
            { text: "เดียวดาย call มาได้เสมอ #IG:chnt.snt", correct: false},
            { text: "เดียวดาย call เคลีย", correct: false},
            { text: "เดียวดาย call เกต", correct: false},
        ]
    }
];

const questionElement = document.getElementById('question');
const answerButton = document.getElementById('answer-btn');
const nextButton = document.getElementById('next-btn');

let currentQuestionIndex = 0;
let score = 0;

function startQuiz(){
    currentQuestionIndex = 0;
    score = 0;
    nextButton.innerHTML = "Next";
    showQuestion();
}

function showQuestion(){
    reset();
    let currentQuestion = questions[currentQuestionIndex];
    let questionNo = currentQuestionIndex + 1;
    questionElement.innerHTML = questionNo + '. ' + currentQuestion.question;

    currentQuestion.answers.forEach(answer => {
        const button = document.createElement('button');
        button.innerHTML = answer.text;
        button.classList.add('btn');
        answerButton.appendChild(button);
        if(answer.correct){
            button.dataset.correct = answer.correct;
        }
        button.addEventListener('click', selectorAnswer)
    })
}

function reset(){
    nextButton.style.display = "none";
    while(answerButton.firstChild){
        answerButton.removeChild(answerButton.firstChild);
    }
}

function selectorAnswer(e){
    const selectedBtn = e.target;
    const isCorrect = selectedBtn.dataset.correct === "true";
    if(isCorrect){
        selectedBtn.classList.add('correct');
        score++;
    }
    else{
        selectedBtn.classList.add('incorrect');
    }
    Array.from(answerButton.children).forEach(button =>{
        if(button.dataset.correct === "true"){
            button.classList.add('correct');
        }
        button.disabled = true;
    });
    nextButton.style.display = 'block';
}

function showScore(){
    reset();
    questionElement.innerHTML = `You Socred ${score} out of ${questions.length}!`;
    nextButton.innerHTML = 'Play Again';
    nextButton.style.display = 'block';
}

function handleNextButton(){
    currentQuestionIndex++;
    if(currentQuestionIndex < questions.length){
        showQuestion();
    }
    else{
        showScore();
    }
}

nextButton.addEventListener('click', ()=>{
    if(currentQuestionIndex < questions.length){
        handleNextButton();
    }
    else{
        startQuiz();
    }
})
startQuiz();