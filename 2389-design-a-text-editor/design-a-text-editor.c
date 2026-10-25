


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#endif
#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

typedef struct {
    char* left;
    int left_size;
    int left_capacity;
    
    char* right;
    int right_size;
    int right_capacity;
} TextEditor;

static void ensure_left_capacity(TextEditor* obj, int additional) {
    if (obj->left_size + additional >= obj->left_capacity) {
        obj->left_capacity = (obj->left_capacity + additional) * 2 + 10;
        obj->left = (char*)realloc(obj->left, obj->left_capacity * sizeof(char));
    }
}

static void ensure_right_capacity(TextEditor* obj, int additional) {
    if (obj->right_size + additional >= obj->right_capacity) {
        obj->right_capacity = (obj->right_capacity + additional) * 2 + 10;
        obj->right = (char*)realloc(obj->right, obj->right_capacity * sizeof(char));
    }
}

TextEditor* textEditorCreate() {
    TextEditor* obj = (TextEditor*)malloc(sizeof(TextEditor));
    obj->left_size = 0;
    obj->left_capacity = 100;
    obj->left = (char*)malloc(obj->left_capacity * sizeof(char));
    
    obj->right_size = 0;
    obj->right_capacity = 100;
    obj->right = (char*)malloc(obj->right_capacity * sizeof(char));
    return obj;
}

void textEditorAddText(TextEditor* obj, char* text) {
    int len = strlen(text);
    ensure_left_capacity(obj, len);
    memcpy(obj->left + obj->left_size, text, len);
    obj->left_size += len;
}

int textEditorDeleteText(TextEditor* obj, int k) {
    int deleted = min(k, obj->left_size);
    obj->left_size -= deleted;
    return deleted;
}

char* get_last_10_left(TextEditor* obj) {
    int start = max(0, obj->left_size - 10);
    int len = obj->left_size - start;
    char* res = (char*)malloc((len + 1) * sizeof(char));
    memcpy(res, obj->left + start, len);
    res[len] = '\0';
    return res;
}

char* textEditorCursorLeft(TextEditor* obj, int k) {
    int move = min(k, obj->left_size);
    for (int i = 0; i < move; i++) {
        ensure_right_capacity(obj, 1);
        obj->right[obj->right_size++] = obj->left[--obj->left_size];
    }
    return get_last_10_left(obj);
}

char* textEditorCursorRight(TextEditor* obj, int k) {
    int move = min(k, obj->right_size);
    for (int i = 0; i < move; i++) {
        ensure_left_capacity(obj, 1);
        obj->left[obj->left_size++] = obj->right[--obj->right_size];
    }
    return get_last_10_left(obj);
}

void textEditorFree(TextEditor* obj) {
    free(obj->left);
    free(obj->right);
    free(obj);
}


/**
 * Your TextEditor struct will be instantiated and called as such:
 * TextEditor* obj = textEditorCreate();
 * textEditorAddText(obj, text);
 
 * int param_2 = textEditorDeleteText(obj, k);
 
 * char* param_3 = textEditorCursorLeft(obj, k);
 
 * char* param_4 = textEditorCursorRight(obj, k);
 
 * textEditorFree(obj);
*/