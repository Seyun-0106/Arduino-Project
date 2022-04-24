// p태그의 dynamic 할당
let target = document.querySelector("#dynamic");
// let Arr = ["Learn to HTML", "Learn to CSS", "Learn to Javascript", "Learn to Python", "Learn to Java"];

// // arr의 길이 미만으로 소수점 버리고 랜덤 숫자 만들어짐
// //(arr.length = 3이면 0, 1, 2 중 하나)
// let selectString = Arr[Math.floor(Math.random() * Arr.length)];

// // selectString의 문자열 하나 하나를 분리시킴
// let selectStringArr = selectString.split("");

function randomString() {
    let Arr = ["Learn to HTML", "Learn to CSS", "Learn to Javascript", "Learn to Python", "Learn to Java"];
    let selectString = Arr[Math.floor(Math.random() * Arr.length)];
    let selectStringArr = selectString.split("");

    return selectStringArr;
}

// 텍스트 값 리셋
function resetTyping() {
    target.textContent = "";
    dynamic(randomString());
}

// 한 글자씩 텍스트 출력하는 함수
function dynamic(randomArr) {
    if (randomArr.length > 0) {
        target.textContent += randomArr.shift();
        // 첫 번째 문자열이 뒤로 빠짐 = 배열의 앞의 값부터 뒤로 빼줌
        setTimeout(function () {
            dynamic(randomArr);
        }, 80);
    }
    else {
        setTimeout(resetTyping, 2000); //2초마다 텍스트 값 리셋
    }
}

dynamic(randomString());

// 0.5초 간격으로 커서 깜빡임 효과
function blink() {
    target.classList.toggle("active");
}

setInterval(blink, 500);