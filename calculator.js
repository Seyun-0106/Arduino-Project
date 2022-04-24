const previous_txt = document.querySelector('.previous');
const current_txt = document.querySelector('.current');
var cnt1 = 0; // current_txx 초기값 0 관련 변수
var cnt2 = 0; // +/- 관련 변수
var cnt3 = 0; // 연산자 버튼 클릭 이후 current_txt 초기화 관련 변수

function append(num) {
    if (cnt1 == 0) {
        current_txt.value = current_txt.value.replace('0', '');
        cnt1 = 1;
    }
    if (cnt3 == 1) {
        current_txt.value = '';
        current_txt.value += num;
        cnt3 = 0;
    }
    else {
        current_txt.value += num;
    }
}
function operation(str) {
    cnt3 = 1;
    if (str == '%') {
        previous_txt.value = eval(previous_txt.value + current_txt.value) + str;
    }
    if (str == '/') {
        previous_txt.value = eval(previous_txt.value + current_txt.value) + str;
    }
    if (str == '+') {
        previous_txt.value = eval(previous_txt.value + current_txt.value) + str;
    }
    if (str == '-') {
        previous_txt.value = eval(previous_txt.value + current_txt.value) + str;
    }
    if (str == '*') {
        previous_txt.value = eval(previous_txt.value + current_txt.value) + str;
    }
    if (str == '+/-') {
        if (cnt2 == 0) {
            current_txt.value = '-' + current_txt.value;
            cnt2 = 1;
        }
        else {
            current_txt.value = current_txt.value.replace('-', '');
            cnt2 = 0;
        }
    }
}
function equals() {
    var e_result = current_txt.value;
    current_txt.value = eval(previous_txt.value + current_txt.value);
    previous_txt.value += e_result + '=';
}

function data_delete() {
    current_txt.value = '';

}
function data_clear() {
    current_txt.value = '0';
    previous_txt.value = '';
    cnt1 = 0;
    cnt2 = 0;
    cnt3 = 0;
}