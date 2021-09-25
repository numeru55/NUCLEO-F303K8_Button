Debounce solution for my NUCLEO-F303K8 buttons.

# Demo Run

- Connect switch to the left side of nucleo as follows:

```
     [PA9]
     [PA10]
     [NRST]
 +-- [GND]
SW   [PA12]
 +-- [PB0]
     [PB7]
     [PB6]
     [PB1]
     [PF0]
     [PF1]
     [PA8]
 +-- [PA11]
SW   [PB5]
 +-- [PB4]
```

Run program, push PB0 or PA11 button. Built-in LED will lit:

+ PB0  ... 1 time
+ PA11 ... 2 times

# How to use

```cpp:
Button_Init(0, GPIOB, GPIO_PIN_0);    // Assign PB0 to button #0.
Button_Init(1, GPIOA, GPIO_PIN_11);   // Assign PA11 to button #1.

while (1) {
	if (Button_Loop(0) == BUTTON_CLICKED) {  // call Button_Loop() function several times. The status will be return.
                // any procedure for clicking PB0.
    		Button_Init(0, GPIOB, GPIO_PIN_0); // to clear button #0 status.
	}
}
```

# Notice

- The button(s) is expected as GND connection with pull-up.  L=PUSH, H=PULL
- This program recognize when "Off-Trigger."
- PB4 is L Output. So equal to GND. 
