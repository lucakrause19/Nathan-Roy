close all;
load ve
load vs
plot(ve(:,1),ve(:,2),'r')
xlabel('t (s)')
ylabel('ve (V)')
axis([0 500*1e-9 -2 2])
title('Reponse du circuit')

hold on

plot(vs(:,1),vs(:,2),'b')
legend('ve', 'vs')
xlabel('t (s)')
ylabel('vs (V)')
axis([0 500*1e-9 -2 2])
