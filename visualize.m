%% Load SPH results

load fluid.dat

t = fluid(:,1);
x = fluid(:,2:2:end);
y = fluid(:,3:2:end);

%% Plots

figure
plot(x, y, '.-')
xlabel('x')
ylabel('y')

figure
subplot 121
plot(t, x, '.-')
xlabel('t')
ylabel('x')
subplot 122
plot(t, y, '.-')
xlabel('t')
ylabel('y')

%% Video

for k=1:length(t)
    if k == 1
        plot(x(k,:), y(k,:), '.')
    else
        plot(x(1:k,:), y(1:k,:), '-', x(k,:), y(k,:), '.')
    end
    xlabel('x')
    ylabel('y')
    title(['t = ' num2str(t(k))])
    drawnow
    %pause
end
