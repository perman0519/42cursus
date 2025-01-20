# miniRT

<img width="715" alt="Screen Shot 2025-01-20 at 2 56 56 PM" src="https://github.com/user-attachments/assets/a18199eb-fdc8-4bb5-91d6-e9c0173c569f" />

## 개요
- **설명**: miniRT는 C 언어와 miniLibX를 사용하여 간단한 레이 트레이싱 기반의 3D 그래픽을 구현하는 프로젝트입니다. 이 프로젝트를 통해 수학적/물리적 공식을 활용하여 컴퓨터 생성 이미지를 생성하는 기초를 배웁니다.
- **목적**: 레이 트레이싱의 기본 개념을 이해하고, 간단한 3D 씬을 렌더링할 수 있는 프로그램을 구현합니다.

---

## 주요 기능
1. **기하학적 객체**:
   - 지원하는 객체: Plane, Sphere, Cylinder.
   - 각 객체의 속성(위치, 크기, 색상) 설정 및 변환(이동, 회전) 가능.
2. **조명 시스템**:
   - Ambient 조명: 전체적인 환경광 설정.
   - Point 조명: 특정 위치에서 빛을 방사.
   - Diffuse 조명: 물체 표면에서 발생하는 난반사 처리.
3. **렌더링**:
   - Ray Tracing 기술을 활용하여 픽셀 단위로 이미지 생성.
   - 섀도우 처리 및 객체 간의 교차점을 정확히 계산.
4. **입력 파일 파싱**:
   - .rt 파일 형식의 씬 설명 파일을 읽어 씬 구성.

---

## 기술적 특징
- **MiniLibX 사용**:
  - 창 생성 및 픽셀 렌더링.
  - 사용자의 입력(키보드, 마우스) 처리.
- **수학적 계산**:
  - 벡터 연산(덧셈, 내적, 외적) 및 광선-객체 교차점 계산.
  - 좌표 변환 및 법선 벡터 계산.
- **성능 최적화**:
  - 효율적인 데이터 구조 및 최소한의 계산 반복을 통해 렌더링 속도 개선.

---

## 빌드 및 실행 방법
1. **필수 요구사항**:
   - Linux 환경.
   - GCC 컴파일러.
   - MiniLibX 라이브러리.
2. **빌드 명령어**:
   ```bash
   make
   ```
3. **실행 명령어**:
   ```bash
   ./miniRT <scene_file.rt>
   ```
   - 예시:
     ```bash
     ./miniRT scenes/example.rt
     ```

---

## .rt 파일 형식 예시
```plaintext
A 0.2 255,255,255
C -50,0,20 0,0,1 70
L -40,0,30 0.7 255,255,255
pl 0,0,0 0,1.0,0 255,0,225
sp 0,0,20 20 255,0,0
cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
```
- **A**: Ambient 조명 (광비율, 색상).
- **C**: 카메라 (위치, 방향 벡터, 시야각).
- **L**: 광원 (위치, 밝기, 색상).
- **pl**: 평면 (위치, 법선 벡터, 색상).
- **sp**: 구체 (중심 좌표, 직경, 색상).
- **cy**: 원기둥 (중심 좌표, 방향 벡터, 직경, 높이, 색상).

---

## 결과
<img width="714" alt="Screen Shot 2025-01-20 at 2 56 38 PM" src="https://github.com/user-attachments/assets/5b9ee619-c258-46cf-abd8-24f02f53d714" />
<img width="703" alt="Screen Shot 2025-01-20 at 2 56 47 PM" src="https://github.com/user-attachments/assets/9af45eb2-e22e-4e47-bd52-5171b2b6d19c" />

- **렌더링 화면**:
  - 씬에서 정의된 객체와 조명 효과를 창에 출력.
  - ESC 키를 눌러 창을 닫고 프로그램 종료.

---

## 느낀 점 및 배운 점
- 수학적 개념(벡터, 교차점 계산)을 실제 코드로 구현하는 경험을 통해 자신감을 얻었습니다.
- 그래픽스와 관련된 기초적인 개념(광원, 색상, 반사 등)을 이해하게 되었습니다.
- MiniLibX를 활용하여 효율적인 창 관리 및 렌더링을 경험했습니다.

---

## 참고 자료
- [레이트레이서를 C 언어로 만들어보는 실습 교재](https://github.com/GaepoMorningEagles/mini_raytracing_in_c)
- [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)
- [MiniLibX Documentation](https://github.com/42Paris/minilibx-linux)

