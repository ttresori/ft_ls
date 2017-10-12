; Set default emacs configuration
(set-language-environment "UTF-8")
(setq-default font-lock-global-modes nil)
(setq-default line-number-mode nil)
(setq-default tab-width 4)
(setq-default indent-tabs-mode t)
(global-set-key (kbd "DEL") 'backward-delete-char)
(setq-default c-backspace-function 'backward-delete-char)
(setq-default c-basic-offset 4)
(setq-default c-default-style "linux")
(setq-default tab-stop-list '(4 8 12 16 20 24 28 32 36 40 44 48 52 56 60
                             64 68 72 76 80 84 88 92 96 100 104 108 112 116 120))
;; Surligne la ligne courante
(global-hl-line-mode 1)
(set-face-background 'hl-line "#333")

;; Affiche les lignes et colonnes dans la barre du bas
(line-number-mode 1)
(column-number-mode 1)

;; Affiche les lignes et colonnes dans la barre du bas
(line-number-mode 1)
(column-number-mode 1)

;; Affiche l'heure dans la barre du bas
(setq display-time-day-and-date t)
(setq display-time-24hr-format t)
(display-time)
(setq european-calendar-style t)

; Surlignage d'une région sélectionnée
(transient-mark-mode t)

;; Montre les parenthèses
(show-paren-mode 1)

;; Descent/monte la fenetre de 2 lines quand le curseur est au bout
(setq scroll-step 10)

;; Reduit la fontion sur elle meme
(add-hook 'c-mode-common-hook 'hs-minor-mode)
(add-hook 'lisp-mode-hook 'hs-minor-mode)
(add-hook 'emacs-lisp-mode-hook 'hs-minor-mode)
(add-hook 'python-mode-hook 'hs-minor-mode)
(global-set-key [f5]  'hs-hide-block)
;; Et la 'de'reduit
(global-set-key [f6] 'hs-show-block)

;; Autorise la sourie
(unless window-system
(require 'mouse)
(xterm-mouse-mode t)
(global-set-key [mouse-4] '(lambda ()
(interactive)
(scroll-down 1)))
(global-set-key [mouse-5] '(lambda ()
(interactive)
(scroll-up 1)))
(defun track-mouse (e))
(setq mouse-sel-mode t)
)

;; Enleve automatiquement les espaces en fin de ligne des qu'on sauvegarde
 (add-hook 'before-save-hook 'delete-trailing-whitespace)
(put 'scroll-left 'disabled nil)

;; Indentation automatique en c-mode
(define-key global-map (kbd "RET") 'newline-and-indent)