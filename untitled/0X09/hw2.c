
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* find_caps(char *caps, const char *str) {
    if (*str == '\0') { // 재귀의 종료 조건: 문자열의 끝에 도달했을 때
        *caps = '\0'; // 대문자로만 이루어진 문자열의 끝을 표시
        return caps;
    }

    if (isupper(*str)) {
        *caps = *str; // 대문자인 경우, 대문자 문자열에 추가
        return find_caps(caps + 1, str + 1); // 다음 문자로 이동
    } else {
        return find_caps(caps, str + 1); // 대문자가 아닌 경우, 다음 문자로 이동
    }
}

int main() {
    const int MAX_SIZE = 100;
    char input[MAX_SIZE];

    printf("Enter a string: \n");
    scanf("%99[^\n]", input); // 개행 문자를 제외한 문자열을 입력 받음

    char *caps = (char *)malloc(strlen(input) + 1);
    if (caps == NULL) {
        printf("메모리 할당 오류\n");
        return 1;
    }

    find_caps(caps, input); // 대문자 문자열 찾기

    if(*caps!='\0')
        printf("Capital letters in %s are %s.\n", input, caps);
    else printf("No capital letter in %s.\n",input);

    free(caps); // 할당된 메모리 해제
    return 0;
}
