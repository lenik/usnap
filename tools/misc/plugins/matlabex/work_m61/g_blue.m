function out = g_blue(img)
% general blur for image testing
%

h = size(img, 1)
w = size(img, 2)
colors = size(img, 3)

out = zeros(h, w, colors);

for y = 2:h-1,
    for x = 2:w-1,
        for c = 1:colors,
            colorsum = 0;
            unitnum = 0;
            for dy = -1:1,
                for dx = -1:1,
                    unitnum = unitnum + 1;
                    % if x+dx in range and y + dy in range ...
                    colorsum = colorsum + img(y + dy, x + dx, c);
                end
            end
            out(y, x, c) = colorsum / 9;
        end
    end
end
