import cv2
import numpy as np

def detectBall(frames):
    frameHSV = cv2.cvtColor(frames, cv2.COLOR_BGR2HSV)
    lower = np.array([30, 40, 50])
    upper = np.array([85, 255, 255])
    mask = cv2.inRange(frameHSV, lower, upper)
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    for cnt in contours:
        area = cv2.contourArea(cnt)
        perimeter = cv2.arcLength(cnt, True)
        approx = cv2.approxPolyDP(cnt, 0.02 * perimeter, True)
        objCor = len(approx)

        if objCor > 4 and area > 500:
            x, y, w, h = cv2.boundingRect(cnt)
            cv2.rectangle(frames, (x, y), (x + w, y + h), (0, 255, 0), 2)
            cv2.putText(frames, "Tennis Ball", (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
        

    return frames

cap = cv2.VideoCapture(0)
cap.set(3, 720)
cap.set(4, 640)

while True:
    success, frames = cap.read()
    if not success:
        break
    outputFrame = detectBall(frames)
    cv2.imshow("Tennis Ball Detection", outputFrame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
