# ECE 6785 — Lab 5 Measurements

## Setup and drift formula

• Oscilloscope: Keysight HD304MSO, 200 MHz, 14-bit
• Programmed half-period delay: 50 ms
• Expected full period: 100 ms; expected frequency: 10 Hz; expected duty cycle: 50%
• Drift in seconds/hour = 3600 × (measured period − 100 ms) / 100 ms.
• Important: Mean period and mean frequency are independently averaged oscilloscope statistics, so they need not be reciprocals. Some captures have spurious period detections.

## Sleep (sleep.c), original

Screenshot time: Oct 20, 2026, 2:56 AM. Horizontal scale: 100.0 ms/div; sample rate: 20.0 MSa/s; memory: 20.0 Mpts. Channel 1: 1.00 V/div; probe 10:1; DC coupling; 1 MΩ. Cursor X1 = −50.000 ms, X2 = +49.984 ms, ΔX = 99.984 ms.

|Measurement |Current |Mean |Min |Max |Std dev |Count |
|--------------------|--------:|--------:|--------:|--------:|---------:|------:|
|Peak-to-peak voltage|4.4304 V |4.3085 V |3.6016 V |4.9312 V |325.22 mV |1.112 k|
|Period |99.98 ms |99.991 ms|99.90 ms |100.00 ms|8.9813 µs |579 |
|Frequency |10.002 Hz|10.001 Hz|10.000 Hz|10.010 Hz|920.89 µHz|523 |
|Negative duty cycle |50.01% |50.000% |49.98% |50.01% |6.6505 m% |495 |

• Drift using 99.991 ms mean: −0.324 s/hr.
• Handwritten calculation uses 99.993 ms: −0.252 s/hr.

## Timer (timer.c), original

Screenshot time: Oct 20, 2026, 2:59 AM. Horizontal scale: 100.0 ms/div; sample rate: 20.0 MSa/s; memory: 20.0 Mpts. Channel 1: 1.00 V/div; 10:1, DC, 1 MΩ. Cursor X1 = −50.000 ms, X2 = +49.984 ms, ΔX = 99.984 ms.

|Measurement |Current |Mean |Min |Max |Std dev |Count |
|--------------------|--------:|--------:|-------:|--------:|--------:|------:|
|Peak-to-peak voltage|4.3425 V |4.2479 V |157.0 mV|4.9604 V |556.60 mV|1.286 k|
|Period |99.98 ms |99.516 ms|16.56 ms|100.02 ms|5.9030 ms|742 |
|Frequency |10.002 Hz|10.245 Hz|9.998 Hz|60.390 Hz|3.2538 Hz|686 |
|Negative duty cycle |49.99% |50.152% |46.60% |98.58% |2.4165% |658 |

• Drift using mean 99.516 ms: −17.424 s/hr (outlier-sensitive).
• Handwritten notes use 99.498 ms: −18.072 s/hr.

## Task-based delay (task)

Screenshot time: Oct 20, 2026, 3:00 AM. Horizontal scale: 100.0 ms/div; sample rate: 20.0 MSa/s; memory: 20.0 Mpts. Channel 1: 1.00 V/div; 10:1, DC, 1 MΩ. Cursor X1 = −50.000 ms, X2 = +49.984 ms, ΔX = 99.984 ms.

|Measurement |Current |Mean |Min |Max |Std dev |Count |
|--------------------|--------:|--------:|-------:|--------:|--------:|------:|
|Peak-to-peak voltage|4.7441 V |4.1961 V |157.0 mV|4.9604 V |705.76 mV|1.350 k|
|Period |99.98 ms |100.27 ms|16.46 ms|755.50 ms|26.038 ms|799 |
|Frequency |10.002 Hz|10.475 Hz|1.324 Hz|60.740 Hz|4.7571 Hz|743 |
|Negative duty cycle |49.99% |50.328% |37.81% |98.58% |3.6429% |715 |

• Drift using mean 100.27 ms: +9.72 s/hr (outlier-sensitive).
• Handwritten notes report 10.08 s/hr.

## Timer modified (timer.c, modified)

Screenshot time: Oct 20, 2026, 3:09 AM. Horizontal scale: 100.0 ms/div; sample rate: 20.0 MSa/s; memory: 20.0 Mpts. Channel 1: 1.00 V/div; 10:1, DC, 1 MΩ. Cursor X1 = −50.000 ms, X2 = +49.984 ms, ΔX = 99.984 ms.

|Measurement |Current |Mean |Min |Max |Std dev |Count|
|-------------------|--------:|--------:|-------:|--------:|--------:|----:|
|Period |99.98 ms |104.26 ms|17.73 ms|107.98 ms|10.056 ms|173 |
|Frequency |10.002 Hz|10.034 Hz|9.261 Hz|56.410 Hz|4.8503 Hz|173 |
|Negative duty cycle|49.99% |50.106% |49.99% |60.80% |997.01 m%|173 |

• Drift using mean 104.26 ms: +153.36 s/hr (outlier-sensitive).
• Handwritten notes report 169.2 s/hr.

## Sleep modified (sleep.c, modified)

Screenshot time: Oct 20, 2026, 3:07 AM. Horizontal scale: 100.0 ms/div; sample rate: 20.0 MSa/s; memory: 20.0 Mpts. Channel 1: 1.00 V/div; 10:1, DC, 1 MΩ. Cursor X1 = −54.000 ms, X2 = +53.984 ms, ΔX = 107.98 ms.

|Measurement |Current |Mean |Min |Max |Std dev |Count|
|-------------------|--------:|--------:|--------:|--------:|--------:|----:|
|Period |107.98 ms|107.98 ms|107.98 ms|107.98 ms|0.0 s |105 |
|Frequency |9.261 Hz |9.2610 Hz|9.261 Hz |9.261 Hz |0.0 Hz |105 |
|Negative duty cycle|49.99% |50.000% |49.99% |50.01% |10.037 m%|105 |

• Drift using 107.98 ms: +287.28 s/hr.
• Handwritten notes: 287.28 s/hr.

## Two-channel timing / delay measurements

### Zoomed-in timing capture

Screenshot: Oct 22, 2026, 2:47 AM. Horizontal scale 200.0 µs/div; sample rate 3.20 GSa/s; memory 6.40 Mpts. CH1: 1.00 V/div, displayed offset 1.620 V; CH2: 10.0 V/div, displayed offset −16.90 V. Cursor positions: 218.75 ns and 2.2500 µs; ΔX = 2.0313 µs.

|Measurement |Current|Mean |Min |Max |Std dev |Count|
|---------------------|------:|--------:|------:|------:|--------:|----:|
|CH1-to-CH2 edge delay|2.28 µs|2.2132 µs|1.97 µs|2.53 µs|122.79 ns|343 |

### Longer time-base capture

Screenshot: Oct 22, 2026, 2:53 AM. Horizontal scale 1.000 s/div; sample rate 2.00 MSa/s; memory 20.0 Mpts. CH1: 200 mV/div, displayed offset −13.78 mV; CH2: 5.00 V/div, displayed offset 1.812 V. Cursor ΔX = 5.1200 ms.

|Measurement |Current|Mean |Min |Max |Std dev |Count|
|---------------------|------:|--------:|------:|-----:|--------:|----:|
|CH1-to-CH2 edge delay|5.1 ms |3.4182 ms|−5.2 ms|7.1 ms|2.9821 ms|67 |

## Handwritten notebook results

|Test |Configured delay|Handwritten drift|
|--------------------------------------|---------------:|----------------:|
|`sleep.c` |50 ms |−0.252 s/hr |
|`timer.c` |50 ms |−18.072 s/hr |
|`task` with delay |50 ms |10.08 s/hr |
|`timer.c` modified |50 ms |169.2 s/hr |
|`task` with second-thread modification|50 ms |288 s/hr |
|`sleep.c` modified |50 ms |287.28 s/hr |

The notebook associates the second-thread modification with 288 s/hr. No separate oscilloscope statistics screenshot for that specific modification was identified in the provided photos.

## Interpretation and measurement caveats

• Original sleep.c appears very close to the expected 100 ms period.
• The original timer and task captures include implausibly short detected periods and wide maxima, which can distort arithmetic means. Use stable-edge cursor measurements or repeated clean acquisitions for a defensible clock-drift estimate.
• The modified sleep capture is stable at 107.98 ms, corresponding to approximately 7.98% longer than the nominal period.
• The 2.2132 µs and 3.4182 ms results are inter-channel edge delays, not clock drift; they must not be interpreted as seconds/hour without additional context.
