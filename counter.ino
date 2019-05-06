int a = D1;
int b = D0;
int c = A1;
int d = A2;
int e = A3;
int f = D2;
int g = D3;
int count = -1;
int button = 0;

void setup() {
    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);
    Particle.variable("button", button);
    Particle.function("toggle", toggle);
}

void loop() {
    while(button == 1) {
        count++;
        int num = count % 10;
        displayNumber(num);
        delay(1000);
    }
}
void displayNumber(int x) {
    int segments[7] = {a, b, c, d, e, f, g};
    int numbers[10][7] =   {{1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0}, {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1},
                            {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1}, {1, 0, 1, 1, 1, 1, 1},
                            {1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};
    
    for (int i = 0; i < 7; i++) {
        if (numbers[x][i] == 1)
            digitalWrite(segments[i], HIGH);
        else
            digitalWrite(segments[i], LOW);
    }
}
int toggle(String extra) {
    int temp = button;
    button = 1-button;
    if (temp == 0) {
        return 1;
    }
    return 0;
}