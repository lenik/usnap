function varargout = Fdemo(varargin)
% FDEMO Application M-file for Fdemo.fig
%    FIG = FDEMO launch Fdemo GUI.
%    FDEMO('callback_name', ...) invoke the named callback.

% Last Modified by GUIDE v2.0 16-Apr-2002 12:12:26

if nargin == 0  % LAUNCH GUI

	fig = openfig(mfilename,'reuse');

	% Use system color scheme for figure:
	set(fig,'Color',get(0,'defaultUicontrolBackgroundColor'));

	% Generate a structure of handles to pass to callbacks, and store it.
	handles = guihandles(fig);
	guidata(fig, handles);

	if nargout > 0
		varargout{1} = fig;
	end

elseif ischar(varargin{1}) % INVOKE NAMED SUBFUNCTION OR CALLBACK

	try
		if (nargout)
			[varargout{1:nargout}] = feval(varargin{:}); % FEVAL switchyard
		else
			feval(varargin{:}); % FEVAL switchyard
		end
	catch
		disp(lasterr);
	end

end


%| ABOUT CALLBACKS:
%| GUIDE automatically appends subfunction prototypes to this file, and
%| sets objects' callback properties to call them through the FEVAL
%| switchyard above. This comment describes that mechanism.
%|
%| Each callback subfunction declaration has the following form:
%| <SUBFUNCTION_NAME>(H, EVENTDATA, HANDLES, VARARGIN)
%|
%| The subfunction name is composed using the object's Tag and the
%| callback type separated by '_', e.g. 'slider2_Callback',
%| 'figure1_CloseRequestFcn', 'axis1_ButtondownFcn'.
%|
%| H is the callback object's handle (obtained using GCBO).
%|
%| EVENTDATA is empty, but reserved for future use.
%|
%| HANDLES is a structure containing handles of components in GUI using
%| tags as fieldnames, e.g. handles.figure1, handles.slider2. This
%| structure is created at GUI startup using GUIHANDLES and stored in
%| the figure's application data using GUIDATA. A copy of the structure
%| is passed to each callback.  You can store additional information in
%| this structure at GUI startup, and you can change the structure
%| during callbacks.  Call guidata(h, handles) after changing your
%| copy to replace the stored original so that subsequent callbacks see
%| the updates. Type "help guihandles" and "help guidata" for more
%| information.
%|
%| VARARGIN contains any extra arguments you have passed to the
%| callback. Specify the extra arguments by editing the callback
%| property in the inspector. By default, GUIDE sets the property to:
%| <MFILENAME>('<SUBFUNCTION_NAME>', gcbo, [], guidata(gcbo))
%| Add any extra arguments after the last argument, before the final
%| closing parenthesis.


%---------------------------
function out = RefreshG(handles)
    nFrom   = str2num(get(handles.nFrom, 'string'));
    nTo = str2num(get(handles.nTo, 'string'));
    nStep = str2num(get(handles.nStep, 'string'));

    Fdesc = get(handles.Fdesc, 'string');
    Ncount = str2num(get(handles.NumCount, 'string'));
    forceT = str2num(get(handles.Fdesc, 'string'));
    if isempty(forceT)
        forceT = [nFrom nTo];
    end
    T = forceT(2) - forceT(1);
    omg = 2 * pi / T;

    cShape = get(handles.cShape, 'string');

    xs = [nFrom:nStep:nTo];
    SymMode = get(handles.Rsym, 'value');
    %--------------------------------------
    if SymMode
        x = sym('x', 'real');
        f = sym('f', 'real');
        f = eval(Fdesc);
        ys = subs(f, x, xs);
    else
        f = Fdesc;
        ys = EvalFVal(f, xs);
    end

    axes(handles.ax);
    hold on;
    plot(xs, ys, cShape);


    a0 = subs(f_a0(f, T));
    for i_A = 1:Ncount,
        a(i_A) = subs(f_ai(f, i_A, T));
        b(i_A) = subs(f_bi(f, i_A, T));
    end
    ys = 0;
    for i_A = Ncount:Ncount,
        ys = ys + ...
            subs(a0 / 2 + ...
            a(i_A) .* cos(i_A .* omg .* xs) + ...
            b(i_A) .* sin(i_A .* omg .* xs) ...
            );
    end

    plot(xs, ys, strcat(cShape, ':'));

% --------------------------------------------------------------------
function varargout = btnRefresh_Callback(h, eventdata, handles, varargin)
    RefreshG(handles);
% --------------------------------------------------------------------
function varargout = nStep_Callback(h, eventdata, handles, varargin)
    if get(handles.AutoRefresh, 'value') == 1
        RefreshG(handles);
    end
% --------------------------------------------------------------------
function varargout = nFrom_Callback(h, eventdata, handles, varargin)
    if get(handles.AutoRefresh, 'value') == 1
        RefreshG(handles);
    end
% --------------------------------------------------------------------
function varargout = nTo_Callback(h, eventdata, handles, varargin)
    if get(handles.AutoRefresh, 'value') == 1
        RefreshG(handles);
    end
% --------------------------------------------------------------------
function varargout = Fdesc_Callback(h, eventdata, handles, varargin)
    if get(handles.AutoRefresh, 'value') == 1
        RefreshG(handles);
    end
% --------------------------------------------------------------------
function varargout = NumCount_Callback(h, eventdata, handles, varargin)
    if get(handles.AutoRefresh, 'value') == 1
        RefreshG(handles);
    end
% --------------------------------------------------------------------
function varargout = cShape_Callback(h, eventdata, handles, varargin)
    if get(handles.AutoRefresh, 'value') == 1
        RefreshG(handles);
    end
% --------------------------------------------------------------------
function varargout = Rsym_Callback(h, eventdata, handles, varargin)
    mutual_exclude(handles.Rm);
    mutual_include(handles.Rsym);
    if get(handles.AutoRefresh, 'value') == 1
        RefreshG(handles);
    end
% --------------------------------------------------------------------
function varargout = Rm_Callback(h, eventdata, handles, varargin)
    mutual_exclude(handles.Rsym);
    mutual_include(handles.Rm);
    if get(handles.AutoRefresh, 'value') == 1
        RefreshG(handles);
    end

%-----------------------------------------------------------------------
function mutual_exclude(off)
    set(off,'Value',0);
%--------------------------------------------------------------------
function mutual_include(on)
    set(on, 'Value', 1);

% --------------------------------------------------------------------
function varargout = ClearFigure_Callback(h, eventdata, handles, varargin)
    axes(handles.ax);
    hold off;
    cla;

% --------------------------------------------------------------------
function varargout = AutoRefresh_Callback(h, eventdata, handles, varargin)

% --------------------------------------------------------------------
function varargout = A_i_plots_Callback(h, eventdata, handles, varargin)

% --------------------------------------------------------------------
function varargout = Function_i_Callback(h, eventdata, handles, varargin)

% --------------------------------------------------------------------
function varargout = B_i_plots_Callback(h, eventdata, handles, varargin)

% --------------------------------------------------------------------
function varargout = SumEstimate_Callback(h, eventdata, handles, varargin)

% --------------------------------------------------------------------
function varargout = forceT_Callback(h, eventdata, handles, varargin)
