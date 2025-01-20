# Philosophers

## 개요
이 프로젝트는 멀티스레드 프로그래밍을 연습하기 위해 설계되었습니다. 철학자들이 식사, 수면, 사고의 상태를 반복하며 데드락을 방지하는 시뮬레이션을 구현합니다. 주요 개념은 **뮤텍스와 세마포어**를 활용하여 자원의 경쟁 상태를 방지하는 것입니다.

---

## 주요 기능
1. **동시성 제어**:
   - 뮤텍스를 사용하여 포크의 상태를 보호.
   - 데이터 경쟁 및 데드락 방지.
2. **시뮬레이션 조건**:
   - 철학자는 순환적으로 식사, 수면, 사고 상태를 반복.
   - 일정 시간 동안 식사를 하지 못하면 철학자는 사망.
3. **로그 시스템**:
   - 각 철학자의 상태 변화(식사, 수면, 사고, 사망)를 시간과 함께 기록.

---

## 기술적 특징
- **뮤텍스 활용**:
  - 각 포크에 대해 pthread_mutex를 사용하여 동기화.
  - 데드락 방지를 위한 알고리즘 적용.
- **정확한 시간 관리**:
  - `gettimeofday`와 `usleep`을 활용하여 밀리초 단위로 시간 관리.
- **스레드 기반 설계**:
  - 철학자 하나당 하나의 스레드를 생성하여 병렬 처리.

---

## 빌드 및 실행 방법
1. **필수 요구사항**:
   - Linux 환경
   - GCC 컴파일러
   - Pthread 라이브러리
2. **빌드 명령어**:
   ```bash
   make
   ```
3. **실행 명령어**:
   ```bash
   ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
   ```
   - 예시:
     ```bash
     ./philo 5 800 200 200
     ```
   - 매개변수:
     - `number_of_philosophers`: 철학자의 수.
     - `time_to_die`: 철학자가 마지막 식사 이후 죽기까지의 시간 (밀리초).
     - `time_to_eat`: 식사 시간 (밀리초).
     - `time_to_sleep`: 수면 시간 (밀리초).
     - `number_of_times_each_philosopher_must_eat`: 각 철학자가 최소 몇 번 식사해야 시뮬레이션이 종료되는지 (선택적).

---

## 결과
- 철학자들의 상태가 다음과 같은 형식으로 기록됩니다:
  ```
  timestamp_in_ms X has taken a fork
  timestamp_in_ms X is eating
  timestamp_in_ms X is sleeping
  timestamp_in_ms X is thinking
  timestamp_in_ms X died
  ```
- 시뮬레이션은 데드락 없이 종료되며, 철학자가 배정된 횟수만큼 식사를 완료했는지 확인할 수 있습니다.

---

## 느낀 점 및 배운 점
- 동기화 기법(뮤텍스, 세마포어)을 활용하여 멀티스레드 프로그래밍의 기초를 다졌습니다.
- 데드락 방지를 위한 알고리즘 설계의 중요성을 실감했습니다.
- 시간 관리 및 스레드 제어의 실질적인 구현 경험을 쌓았습니다.

---

## 참고 자료
- [Dining Philosophers Problem - Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [POSIX Threads Programming Guide](https://man7.org/linux/man-pages/man7/pthreads.7.html)

