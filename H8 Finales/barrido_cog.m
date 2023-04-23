%% Barrido de COG
% for x = 0.06:0.04:0.14
%     for y = 0.01:0.02:0.05
%         x_lev12 = 0.50086 + x;
%         x_lev34 = 0.48414 - x;
%         x_guid12 = 0.50503 + x;
%         x_guid34 = 0.48831 - x;
%         y_lev13 = 0.23523 - y;
%         y_lev24 = 0.23827 + y;
%         y_guid13 = 0.2372 - y;
%         y_guid24 = 0.2402 + y;
%         sim("H8_6GDL_nolineal.slx");
%     end
% end
y = 0;
for x = 0.06:0.04:0.10
        x_lev12 = 0.50086 + x;
        x_lev34 = 0.48414 - x;
        x_guid12 = 0.50503 + x;
        x_guid34 = 0.48831 - x;
        y_lev13 = 0.23523 - y;
        y_lev24 = 0.23827 + y;
        y_guid13 = 0.2372 - y;
        y_guid24 = 0.2402 + y;
        sim("H8_6GDL_nolineal.slx");
end
